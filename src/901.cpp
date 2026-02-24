#include "../include.h"

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int days = 1;

        while (!st.empty() && st.top().first <= price) {
            days += st.top().second;
            st.pop();
        }

        st.push({price, days});
        return days;
    }
};