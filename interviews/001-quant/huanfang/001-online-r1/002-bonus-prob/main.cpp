#include<cstdio>
#include<climits>
#include<iostream>
#include<map>

int get_digit_num(long long num) {
    int result = 0;
    while(num) {
        result |= (1 << (num % 10));
        num /= 10;
    }
    return result;
}


double solve(long long L, long  long R) {
    std::map<int, int> m;
    for (long long i = L; i <= R; i++) {
        m[get_digit_num(i)]++;
    }
    long long valid_group = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second < 2) {
            continue;
        }
        valid_group += (iter->second & 1) ? (iter->second) * ((iter->second - 1) >> 1) : ((iter->second >> 1) * (iter->second - 1));
    }
    
    long long diff = R - L;
    long long total_group = ((diff & 1) ? (diff * ((diff + 1) >> 1)) : ((diff >> 1) * (diff + 1)));
    return double(valid_group) / double(total_group);
}

int main() {
    long long L,R;
    scanf("%lld%lld", &L, &R);
    printf("%.6lf\n",solve(L, R));
    return 0;
}
