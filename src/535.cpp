#include "../include.h"

class Solution {
public:
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unordered_map<string, string> codes, urls;

    string fake_hash() {
        string code = "";

        for (int i = 0; i < 6; i++)
            code += chars[rand() % 62];

        return "http://tinyurl.com/" + code;
    }

    string encode(string longUrl) {
        if (codes.find(longUrl) != codes.end()) return codes[longUrl];

        string c = fake_hash();

        while (urls.find(c) != urls.end()) c = fake_hash();

        urls[c] = longUrl;
        codes[longUrl] = c;

        return c;
    }

    string decode(string shortUrl) {
        return urls[shortUrl];
    }
};