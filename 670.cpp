#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int maximumSwap(int num);


int main(int argc, char const *argv[])
{
	cout << maximumSwap(2376) << endl;
	return 0;
}



int maximumSwap(int num) {
    if(num < 12) {
        return num;
    }
    int s = (int)log10(double(num)) + 1;
    vector<int> v;
    while (num) {
        v.push_back(num % 10);
        num /= 10;
    }
    int max_num = num;
    for (int i = 0; i < s; i++) {
        for (int j = i; j < s; j++) {
            swap(v[i], v[j]);
            int tmp = 0;
            for (int k = 0; k < s; k++) {
                tmp += v[k] * (int)pow(10, k);
            }
            cout << "after swap: " << tmp << endl;

            swap(v[i], v[j]);
            max_num = max(max_num, tmp);
        }
    }
    return max_num;
}
