#include <iostream>

using namespace std;


// lazy singleton
class SingletonMode {
public:
	// lazy方式，先不生成对象，只有显式调用instance()时才会生成对象，对于比较占内存的对象较为友好。
	static SingletonMode& instance() { // 返回引用而不是指针是防止外部操作使用delete释放对象
		if (_instance == NULL) {  // 这个语句非线程安全
			_instance = new SingletonMode;
		}
		return *_instance;
	}

private:
	// 构造函数、复制构造函数、赋值运算符重载都定为private杜绝了生成新对象的途径
	SingletonMode();
	~SingletonMode(); 
	SingletonMode(const SingletonMode&);
	SingletonMode& operator=(const SingletonMode &);

	static SingletonMode * _instance;
};



// eager singleton， 与lazy相反
class EagerSingleton{
public:
	static EagerSingleton& instance() { // 在main函数外部就构造对象。
		return instance;
	}
private:
	EagerSingleton();
	~EagerSingleton();
	EagerSingleton(const EagerSingleton&);
	EagerSingleton& operator= (const EagerSingleton&);
	static EagerSingleton instance;
};


class MayersSingleton{
public:
	static MayersSingleton& instance() {
		static MayersSingleton instance;
		return instance;
	}
private:
	MayersSingleton();
	~MayersSingleton();
	MayersSingleton(const MayersSingleton&);
	MayersSingleton & operator= (const MayersSingleton&);
};



class DoubleCheckLockPattern
{
public:
	static DoubleCheckLockPattern& instance(){
		if (_instance == NULL) {
			Lock lock; // 基于作用域的锁，出了作用域调用析构函数自动解锁
			if (_instance == NULL) _instance = new DoubleCheckLockPattern;
		}
		return *_instance;
	}
private:
	DoubleCheckLockPattern();
	~DoubleCheckLockPattern();
	DoubleCheckLockPattern(const DoubleCheckLockPattern&);
	DoubleCheckLockPattern& operator= (const DoubleCheckLockPattern&);
	static DoubleCheckLockPattern* _instance;
	
};



// 尽管pthread_once()调用会出现在多个线程中，init_routine()函数仅执行一次，pthread_once是很适合用来实现线程安全单例
template <typename T> class ThreadSingleton : boost::nocopyable {
public:
	static ThreadSingleton& instance() {
		pthread_once(&_ponce, &ThreadSingleton::init);
		return *_value;
	}
	static void init() {
		_value = new T();
	}

private:
	static pthread_once_t _ponce;
	static ThreadSingleton* _value;
}




int main() {
	SingletonMode * SingletonMode::_instance = NULL;
	EagerSingleton EagerSingleton::instance;
	return 0;
}


