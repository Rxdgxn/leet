#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define sort_v(v) sort((v).begin(), (v).end())

template <typename T>
void vout(vector<T> v, string del) {
    for (T val : v) cout << val << del;
    cout << "\n";
}