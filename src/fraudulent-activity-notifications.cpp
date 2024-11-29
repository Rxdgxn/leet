#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int occ[201];

// Bullshit function because using while loops doesnt work
int get_element_with_rank(int r) {
    int c = 0;
    
    for (int i = 0; i <= 200; i++) {
        c += occ[i];
        if(c >= r) return i;
    }

    return 200;
}

int activityNotifications(vector<int> expenditure, int d) {
    const int n = expenditure.size();
    int notifs = 0;

    queue<int> q;

    for (int i = 0; i < d; i++) {
        occ[expenditure[i]]++;
        q.push(expenditure[i]);
    }

    for (int i = d; i < n; i++) {
        int x = 0, amount;
        
        if (d % 2) amount = 2 * get_element_with_rank((d + 1) / 2);
        else amount = get_element_with_rank(d / 2) + get_element_with_rank(d / 2 + 1);

        if (expenditure[i] >= amount) notifs++;

        occ[q.front()]--;
        q.pop();
        occ[expenditure[i]]++;
        q.push(expenditure[i]);
    }

    return notifs;
}

int main(void) {
    int x, d;
    cin >> x >> d;
    vector<int> v(x);

    for (int i = 0; i < x; i++) cin >> v[i];

    cout << activityNotifications(v, d);

    return 0;
}
