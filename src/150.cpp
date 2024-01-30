#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int stoi(string& s) {
        const int len = s.size();
        int ret = 0, p = 1;

        for (int i = 1; i < len; i++) {
            ret = ret * 10 + (s[i] - '0');
            p *= 10;
        }
        
        if (s[0] == '-') return -ret;

        return (s[0] - '0') * p + ret;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& tok : tokens) {
            if (tok.size() == 1 && strchr("+-*/", tok[0])) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                switch (tok[0]) {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(a - b);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push(a / b);
                    break;
                default:
                    break;
                }
            }
            else {
                st.push(stoi(tok));
            }
        }

        return st.top();
    }
};