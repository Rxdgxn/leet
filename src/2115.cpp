#include "../include.h"

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        vector<string> ret;

        int new_recipes;
        const int n = recipes.size();

        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);

        do {
            new_recipes = 0;
            int k = q.size();

            while (k--) {
                int i = q.front();
                q.pop();

                bool ok = true;

                for (const string& ing : ingredients[i])
                    if (available.find(ing) == available.end()) {
                        ok = false;
                        break;
                    }

                if (ok) {
                    new_recipes = 1;

                    ret.push_back(recipes[i]);
                    available.insert(recipes[i]);
                }
                else q.push(i);
            }

        } while (new_recipes);

        return ret;
    }
};