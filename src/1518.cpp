class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0;

        while (numBottles >= numExchange) {
            int q = numBottles / numExchange;
            total += q * numExchange;

            numBottles %= numExchange;
            numBottles += q;
        }

        total += numBottles;

        return total;
    }
};