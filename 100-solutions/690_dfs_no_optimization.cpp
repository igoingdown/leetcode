/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        for (auto e : employees) {
            if (e->id == id) {
                res += e->importance;
                for (int sub_id : e->subordinates) {
                    res += getImportance(employees, sub_id);
                }
            }
        }
        return res;
    }
};