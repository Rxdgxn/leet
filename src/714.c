#include <stdlib.h>

int maxProfit(int* prices, int pricesSize, int fee) {
    int buy = INT_MIN;
    int sell = 0;

    for (int i = 0; i < pricesSize; i++) {
        buy = max(buy, sell - prices[i]);
        sell = max(sell, buy + prices[i] - fee);
    }

    return sell;
}