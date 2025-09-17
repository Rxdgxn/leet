#include "../include.h"

class FoodRatings {
public:
    typedef pair<string, int> rating;

    struct Compare {
        bool operator() (const rating& a, const rating& b) const {
            if (a.second < b.second) return false;
            if (a.second > b.second) return true;
            
            return a.first < b.first;
        }
    };

    typedef set<rating, Compare> CustomSet;

    unordered_map<string, CustomSet> cuisines;
    unordered_map<string, string> belonging;
    unordered_map<string, int> ratings;

    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        const int n = f.size();

        for (int i = 0; i < n; i++) {
            cuisines[c[i]].insert({f[i], r[i]});
            belonging[f[i]] = c[i];
            ratings[f[i]] = r[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = belonging[food];
        int r = ratings[food];

        cuisines[c].erase({food, r});
        cuisines[c].insert({food, newRating});

        ratings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisines[cuisine].begin()->first;
    }
};