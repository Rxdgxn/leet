#include "../include.h"

class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sw) {
        int n = st.size();

        queue<int> students;
        stack<int> sandwiches;

        for (int s : st) students.push(s);
        for (int i = n - 1; i >= 0; i--) sandwiches.push(sw[i]);

        int rotated = 0;

        while (!students.empty() && rotated < students.size()) {
            if (sandwiches.top() == students.front()) {
                rotated = 0;
                sandwiches.pop();
                students.pop();
            }
            else {
                rotated++;
                students.push(students.front());
                students.pop();
            }
        }

        return students.size();
    }
};