#include "../include.h"

class AuthenticationManager {
public:
    // TODO: speed
    unordered_map<string, int> available_tokens;
    int aliveTime;

    AuthenticationManager(int timeToLive) {
        aliveTime = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        available_tokens[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        const int t = available_tokens[tokenId];
        if (t && currentTime - t >= aliveTime) available_tokens[tokenId] = 0;
        if (available_tokens[tokenId]) generate(tokenId, currentTime);
    }
    
    int countUnexpiredTokens(int currentTime) {
        int t = 0;

        for (auto it = available_tokens.begin(); it != available_tokens.end(); it++) {
            if (available_tokens[it->first]) {
                if (currentTime - it->second < aliveTime) t++;
                else available_tokens[it->first] = 0;
            }
        }

        return t;
    }
};