#include "../include.h"

class ProductOfNumbers {
public:
    vector<int> products;

    ProductOfNumbers() {
        products.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            products.clear();
            products.push_back(1);
        }
        else products.push_back(num * products.back());
    }
    
    int getProduct(int k) {
        const int n = products.size() - 1;

        if (k > n) return 0;

        return products.back() / products[n - k];
    }
};