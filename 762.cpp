#include <iostream>
#include <set>

using namespace std;

int countPrimeSetBits(int L, int R);

int main() {
	cout << countPrimeSetBits(10, 15) << endl;
	return 0;
}

int countPrimeSetBits(int L, int R) {
    set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int res = 0;
    for (int i = L; i <= R; i++) {
        bitset<32> b(i);
        if (primes.find(b.count()) != primes.end()) res++;
    }
    return res;
}