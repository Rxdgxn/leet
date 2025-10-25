#include "../include.h"

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> views_per_creator;
        unordered_map<string, int> max_views_of_video;
        unordered_map<string, string> most_viewed_id;

        set<string> most_popular;
        long long pop = 0;

        const int n = creators.size();

        for (int i = 0; i < n; i++) {
            const string& c = creators[i];
            const int& v = views[i];
            const string& id = ids[i];

            views_per_creator[c] += v;

            if (views_per_creator[c] > pop) {
                pop = views_per_creator[c];
                most_popular.clear();
                most_popular.insert(c);
            }
            else if (views_per_creator[c] == pop) {
                most_popular.insert(c);
            }

            if (max_views_of_video.find(c) == max_views_of_video.end()) {
                max_views_of_video.insert(make_pair(c, v));
                most_viewed_id.insert(make_pair(c, id));
                continue;
            }

            if (v > max_views_of_video[c] || (v == max_views_of_video[c] && id < most_viewed_id[c])) {
                max_views_of_video[c] = v;
                most_viewed_id[c] = id;
            }
        }

        vector<vector<string>> ret;

        for (string c : most_popular) {
            ret.push_back({c, most_viewed_id[c]});
        }

        return ret;
    }
};