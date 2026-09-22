#include "../include.h"

class TopVotedCandidate {
private:
    map<int, int> leading_at_time;
    unordered_map<int, int> votes;
    map<int, vector<int>> by_votes;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        const int n = persons.size();

        // This uses more memory than it should, because it doesnt clear people from smaller votes buckets, but the constraints are small
        for (int i = 0; i < n; i++) {
            by_votes[++votes[persons[i]]].push_back(persons[i]);
            leading_at_time[times[i]] = by_votes.rbegin()->second.back();
        }
    }
    
    int q(int t) {
        return prev(leading_at_time.upper_bound(t))->second;
    }
};