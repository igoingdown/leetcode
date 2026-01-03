#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

// 演示：在没有同步的情况下，编译器/CPU/缓存可能导致读线程看不到写线程的写入。
// 这个示例包含两个测试：
// 1) non-volatile：使用普通的全局 bool flag_nonvolatile（未使用 volatile/atomic）
//    读线程在 while (!flag_nonvolatile) {} 中忙等待，编译器可能把 flag 缓存在寄存器里，导致读线程永远看不到写线程的写入（在有些编译优化下会卡住）。
// 2) volatile：使用 volatile 修饰的全局变量 flag_volatile，同样的 busy-wait 可以避免编译器把读操作优化掉，因此在很多平台上读线程会看到变化并退出。
// 注意：这只是演示 "为什么会出错" 与 "volatile 的效果"（volatile 可能阻止编译器缓存优化），但 volatile 并不是正确的线程同步手段。
// 正确的做法是使用 std::atomic 或者其他同步原语（mutex/condition_variable）。

static bool flag_nonvolatile = false;    // 未同步的全局变量（可能导致不可见）
static volatile bool flag_volatile = false; // 使用 volatile，阻止编译器将读缓存到寄存器

// 辅助：等待 done 标志的超时检测
bool wait_done_with_timeout(std::atomic<bool> &done, int timeout_ms)
{
    int waited = 0;
    while (!done.load()) {
        if (waited >= timeout_ms) return false;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        waited += 5;
    }
    return true;
}

void test_nonvolatile()
{
    std::cout << "--- test_nonvolatile (expect: may hang without volatile) ---\n";
    flag_nonvolatile = false;
    std::atomic<bool> done{false};

    // 读线程：忙等待非原子/非volatile 变量
    std::thread reader([&]() {
        // 这里编译器有权假设没有其他线程会修改 flag_nonvolatile（因为它不是 volatile/atomic），
        // 因此在优化级别较高时，可能会把 flag_nonvolatile 的值加载到寄存器并重复使用，从而导致死循环。
        while (!flag_nonvolatile) {
            // 为了加大“被优化掉”的概率，读循环体为空
            ;
        }
        done.store(true);
        std::cout << "reader (nonvolatile) exiting\n";
    });

    // 写线程：等待短暂时间后写入
    std::thread writer([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        flag_nonvolatile = true; // 写入
        std::cout << "writer (nonvolatile) set flag_nonvolatile = true\n";
    });

    // 等待 reader 完成，最多 1000ms
    bool ok = wait_done_with_timeout(done, 1000);
    if (ok) std::cout << "nonvolatile: reader observed the write (SUCCESS)\n";
    else std::cout << "nonvolatile: reader DID NOT observe the write within timeout (LIKELY STUCK)\n";

    // 清理线程（如果 reader 被卡住，这里先尝试分离，程序继续）
    if (reader.joinable()) {
        // 如果 ok==true，则 reader 已经退出并可 join
        if (ok) reader.join();
        else reader.detach();
    }
    if (writer.joinable()) writer.join();
}

void test_volatile()
{
    std::cout << "--- test_volatile (volatile used) ---\n";
    flag_volatile = false;
    std::atomic<bool> done{false};

    std::thread reader([&]() {
        // 由于 flag_volatile 是 volatile，编译器在每次循环测试时会从内存读取它，
        // 因而读线程更有可能看到写线程的更改并退出。注意这仍然不是线程安全的保证。
        while (!flag_volatile) {
            ;
        }
        done.store(true);
        std::cout << "reader (volatile) exiting\n";
    });

    std::thread writer([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        flag_volatile = true;
        std::cout << "writer (volatile) set flag_volatile = true\n";
    });

    bool ok = wait_done_with_timeout(done, 1000);
    if (ok) std::cout << "volatile: reader observed the write (SUCCESS)\n";
    else std::cout << "volatile: reader DID NOT observe the write within timeout (UNEXPECTED)\n";

    if (reader.joinable()) reader.join();
    if (writer.joinable()) writer.join();
}

int main()
{
    std::cout << "Demo: volatile vs non-volatile in multithreaded busy-wait (undefined-behavior demo)\n";
    std::cout << "Compiling/Running with optimizations (-O2/-O3) 更容易观测到差异。" << std::endl;

    test_nonvolatile();
    test_volatile();

    std::cout << "--- now show correct approach using std::atomic ---\n";

    // 正确做法示例：用 std::atomic<bool>
    std::atomic<bool> flag_atomic{false};
    std::atomic<bool> done{false};

    std::thread r([&]() {
        while (!flag_atomic.load(std::memory_order_acquire)) {
            ;
        }
        done.store(true);
        std::cout << "reader (atomic) exiting\n";
    });
    std::thread w([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        flag_atomic.store(true, std::memory_order_release);
        std::cout << "writer (atomic) set flag_atomic = true\n";
    });

    if (r.joinable()) r.join();
    if (w.joinable()) w.join();
    if (done.load()) std::cout << "atomic: reader observed the write (CORRECT)\n";

    return 0;
}
