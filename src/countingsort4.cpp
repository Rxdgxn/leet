#include "../include.h"

struct Content {
    bool is_dash = false;
    string inner = "";
};

void countSort(vector<vector<string>> arr) {
    unordered_map<int, vector<Content>> mp;
    vector<int> keys;
    const int sz = arr.size();

    for (int i = 0; i < sz; i++) {
        Content c;
        if (i < sz / 2) c.is_dash = true;
        else c.inner = arr[i][1];

        int key = stoi(arr[i][0]);
        if (find(keys.begin(), keys.end(), key) == keys.end()) keys.push_back(key);

        mp[key].push_back(c);
    }

    sort(keys.begin(), keys.end());

    for (int key : keys) {
        for (const Content& c : mp[key]) {
            cout << (c.is_dash ? "-" : c.inner) << " ";
        }
    }
}

int main(void) {

    int n;
    cin >> n;
    vector<vector<string>> arr(n, vector<string>(2));

    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];

    countSort(arr);

    return 0;
}