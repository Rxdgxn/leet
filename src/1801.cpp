#include "../include.h"

struct Order {
    int price, amount, type;
};

class SellCompare {
public:
    bool operator() (const Order& a, const Order& b) {
        return a.price > b.price;
    }
};

class BuyCompare {
public:
    bool operator() (const Order& a, const Order& b) {
        return a.price < b.price;
    }
};

class Solution {
public:
    const int MOD = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<Order, vector<Order>, SellCompare> sell_log;
        priority_queue<Order, vector<Order>, BuyCompare> buy_log;

        for (auto& o : orders) {
            Order order = {o[0], o[1], o[2]};

            if (order.type == 0) {
                while (!sell_log.empty() && sell_log.top().price <= order.price && order.amount > 0) {
                    Order top = sell_log.top();
                    sell_log.pop();

                    if (top.amount > order.amount) {
                        top.amount -= order.amount;
                        order.amount = 0;
                        sell_log.push(top);
                    }
                    else {
                        order.amount -= top.amount;
                    }
                }

                if (order.amount > 0) {
                    buy_log.push(order);
                }
            }
            else {
                while (!buy_log.empty() && buy_log.top().price >= order.price && order.amount > 0) {
                    Order top = buy_log.top();
                    buy_log.pop();

                    if (top.amount > order.amount) {
                        top.amount -= order.amount;
                        order.amount = 0;
                        buy_log.push(top);
                    }
                    else {
                        order.amount -= top.amount;
                    }
                }

                if (order.amount > 0) {
                    sell_log.push(order);
                }
            }
        }

        long long ret = 0;

        while (!sell_log.empty()) {
            ret = (ret + sell_log.top().amount) % MOD;
            sell_log.pop();
        }

        while (!buy_log.empty()) {
            ret = (ret + buy_log.top().amount) % MOD;
            buy_log.pop();
        }

        return ret;
    }
};