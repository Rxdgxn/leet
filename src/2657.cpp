#include "../include.h"

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();

        vector<int> C(n);
        C[0] = (A[0] == B[0]);

        unordered_map<int, int> a, b;

        a[A[0]] = 1;
        b[B[0]] = 1;

        for (int i = 1; i < n; i++) {
            a[A[i]] = 1;
            b[B[i]] = 1;

            C[i] = C[i - 1] + b[A[i]] + a[B[i]] - (A[i] == B[i]);
        }

        return C;
    }
};