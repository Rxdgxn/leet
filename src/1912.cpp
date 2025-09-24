#include "../include.h"

class MovieRentingSystem {
public:
    typedef pair<int, int> Duo;

    map<int, set<Duo>> rented_movies, unrented_movies; // price -> (shop, movie)
    map<Duo, int> specific_price; // (shop, movie) -> price
    unordered_map<int, set<Duo>> cheapest_shops; // movie -> (price, shop);

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            specific_price[{entry[0], entry[1]}] = entry[2];
            unrented_movies[entry[2]].insert({entry[0], entry[1]});
            cheapest_shops[entry[1]].insert({entry[2], entry[0]});
        }
    }
    
    vector<int> search(int movie) {
        auto& s = cheapest_shops[movie];

        vector<int> shops;
        int i = 0;

        for (auto it = s.begin(); it != s.end() && i < 5; it++, i++)
            shops.push_back(it->second);

        return shops;
    }
    
    void rent(int shop, int movie) {
        int p = specific_price[{shop, movie}];

        unrented_movies[p].erase({shop, movie});
        cheapest_shops[movie].erase({p, shop});

        rented_movies[p].insert({shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = specific_price[{shop, movie}];

        unrented_movies[p].insert({shop, movie});
        cheapest_shops[movie].insert({p, shop});

        rented_movies[p].erase({shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret;
        int i = 0;

        for (auto it = rented_movies.begin(); it != rented_movies.end() && i < 5; it++) {
            if (it->second.empty()) continue;

            for (auto duo_it = it->second.begin(); duo_it != it->second.end() && i < 5; duo_it++, i++)
                ret.push_back({duo_it->first, duo_it->second});
        }

        return ret;
    }
};