class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, total = 0;
        // start表示可能成为解的station的index。
        // tank表示从start走到i油箱里还有多少油
        // total表示从station 0走到station start的剩余油量（<=0）
        // total + tank就是总的剩余油量

        // 3个关键点
        // 1. 如果从i无法走到j，则从i和j之间的任意位置都走不动j
        // 2. 如果total + tank >= 0则必有解
        // 3. 如果有解，解必为start，因为start之前的station不是解，如果之后的位置是解，由于start可以到达该位置，因此start也是解。
        for (int i = 0; i < gas.size(); i++) {
            if ((tank = tank + gas[i] - cost[i]) < 0) {
                total += tank; tank = 0; start = i + 1;
            }
        }
        return total + tank < 0 ? -1 : start;
    }
};