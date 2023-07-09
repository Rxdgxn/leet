#include "../include.h"

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), cmp);
    return unsorted;
}

int main(void) {
    int n;
    cin >> n;
    vector<string> input(n);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    auto xs = bigSorting(input);

    for (string x : xs) {
        cout << x << endl;
    }

    return 0;
}