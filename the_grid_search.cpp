#include "include.h"

ifstream fin("input.txt");
typedef long long ll;
#define NPOS string::npos

vector<ll> indexes(string src, string target) {
    vector<ll> ret;
    ll idx = 0;
	while ((idx = src.find(target, idx)) != NPOS) {
		ret.push_back(idx);
		idx += target.size();
	}
    return ret;
}

bool uniques(vector<string> src, ll i, ll j, ll idx) {
    for (int k = i; k < j; k++)
        if (src[k+1].substr(0, idx) != src[k].substr(0, idx)) return 0;
    return 1;
}

string gridSearch(vector<string> G, vector<string> P) {
    bool ok;
    ll gsz = G.size(), psz = P.size();

    for (ll i = 0; i < gsz; i++) {
        auto idxs = indexes(G[i], P[0]);
        for (ll idx : idxs) {
            ok = 1;
            if (idx != NPOS) {
                for (ll j = i + 1; j < i + psz && j < gsz && ok; j++) {
                    ll n = G[j].find(P[j - i]);
                    if (n == NPOS || (n != idx && !uniques(G, i, j, n))) ok = 0;
                }
            }
            if (ok && idx != NPOS) return "YES";
        }
    }
    return "NO";
}

int main() {

    int t;
    fin >> t;
    for (int i = 0; i < t; i++) {
        string aux;
        vector<string> G, P;
        int r, c, R, C;

        fin >> R >> C;
        for (int j = 0; j < R; j++) {
            fin >> aux;
            G.push_back(aux);
        }

        fin >> r >> c;
        for (int j = 0; j < r; j++) {
            fin >> aux;
            P.push_back(aux);
        }

        cout << gridSearch(G, P) << endl;
    }

    return 0;
}