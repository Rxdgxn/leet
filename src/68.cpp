#include "../include.h"

class Solution {
public:
    void justify(pair<string, int>& line, int maxWidth) {
        string& l = line.first;
        int slots = line.second - 1;
        int remainingSpaces = maxWidth - l.size();

        if (slots > 0) {
            int each = remainingSpaces / slots;
            int extra = remainingSpaces % slots;

            for (int i = 0; i < l.size(); i++) {
                if (l[i] == ' ') {
                    for (int j = 0; j < each; j++)
                        l.insert(l.begin() + i, ' ');
                    
                    i += each + 1;

                    if (extra) {
                        l.insert(l.begin() + i - each - 1, ' ');
                        i++;
                        extra--;
                    }
                }
            }
        }
        else {
            int r = maxWidth - l.size();

            while (r--)
                l += ' ';
        }
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        pair<string, int> line = {"", 0};

        for (string& word : words) {
            if (line.first.size() + word.size() + 1 > maxWidth) {
                if (!line.first.empty()) {
                    justify(line, maxWidth);
                    lines.push_back(line.first);
                    
                    line.first = word;
                    line.second = 1;

                    continue;
                }
            }

            if (!line.first.empty())
                line.first += ' ';
            line.first += word;
            line.second++;
        }

        if (!line.first.empty()) {
            int r = maxWidth - line.first.size();

            while (r--)
                line.first += ' ';

            lines.push_back(line.first);
        }

        return lines;
    }
};