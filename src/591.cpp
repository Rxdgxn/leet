#include "../include.h"

class Solution {
public:
    enum ParseState {
        OPEN_TAG,
        CLOSE_TAG,
        NORMAL,
        CDATA
    };

    bool isValid(string code) {
        const int n = code.size();

        if (n < 2) // could further pump this limit up
            return false;;
        
        if (code[0] != '<' || code[1] == '!' || code[1] == '/')
            return false;
        
        stack<string> tags;
        string curr_tag = "";

        ParseState state = OPEN_TAG;

        int i = 1;

        while (i < n) {
            char ch = code[i];

            switch (state) {
            case OPEN_TAG:
                if (ch == '>') {
                    if (curr_tag.empty())
                        return false;

                    i += 1;
                    state = NORMAL;

                    tags.push(curr_tag);
                    curr_tag = "";
                }
                else if (ch == '!') {
                    if (i + 7 >= n || code.substr(i + 1, 7) != "[CDATA[")
                        return false;

                    i += 8;
                    state = CDATA;
                }
                else if ('A' <= ch && ch <= 'Z') {
                    curr_tag += ch;

                    if (curr_tag.size() > 9)
                        return false;

                    i += 1;
                }
                else {
                    return false;
                }

                break;
            case CLOSE_TAG:
                if (ch == '>') {
                    if (curr_tag.empty())
                        return false;

                    i += 1;
                    state = NORMAL;

                    if (tags.empty() || tags.top() != curr_tag)
                        return false;

                    tags.pop();
                    curr_tag = "";

                    if (tags.empty() && i != n)
                        return false;
                }
                else if ('A' <= ch && ch <= 'Z') {
                    curr_tag += ch;

                    if (curr_tag.size() > 9)
                        return false;

                    i += 1;
                }
                else {
                    return false;
                }

                break;
            case NORMAL:
                if (ch == '<') {
                    if (i + 1 >= n)
                        return false;

                    if (code[i + 1] == '/') {
                        state = CLOSE_TAG;
                        i += 2;
                        break;
                    }

                    state = OPEN_TAG;
                    i += 1;
                }
                else {
                    i += 1;
                }
                
                break;
            case CDATA:
                while (i < n) {
                    if (code[i] == ']') {
                        if (i + 2 >= n)
                            return false;

                        if (code[i + 1] == ']' && code[i + 2] == '>') {
                            i += 3;
                            state = NORMAL;
                            break;
                        }
                    }

                    i += 1;
                }

                break;
            default:
                break;
            }
        }

        return tags.empty() && state == NORMAL;
    }
};