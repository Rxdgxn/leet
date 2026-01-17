#include "../include.h"

class Compare {
public:
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		return a.first < b.first;
	}
};

// Apparently the dumb way is the good way?
class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<int>> posts;
    unordered_map<int, int> date_posted;
    int timestamp = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back(tweetId);
        date_posted[tweetId] = timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (int f : following[userId])
            for (int tweet : posts[f])
                pq.push({date_posted[tweet], tweet});

        for (int tweet : posts[userId])
            pq.push({date_posted[tweet], tweet});

        vector<int> ret;
        int taken = 0;

        while (!pq.empty() && taken < 10) {
            ret.push_back(pq.top().second);
            pq.pop();
            taken++;
        }

        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};