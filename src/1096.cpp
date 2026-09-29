#include "../include.h"

// Note: extremely slow approach, not only because of the sets, but also because of all the string copying, which probably happens more than it should
class Solution {
private:
    void setUnion(set<string>& dest, const set<string>& src) {
        for (auto& s : src) {
            dest.insert(s);
        }
    }

    set<string> concatenate(set<string>& group, string& s) {
        if (group.empty()) {
            return {s};
        }

        set<string> ret;

        for (auto& x : group) {
            ret.insert(x + s);
        }

        return ret;
    }

    set<string> concatenate(set<string>& group1, set<string>& group2) {
        if (group1.empty()) {
            return group2;
        }

        set<string> ret;

        for (auto& i : group1) {
            for (auto& j : group2) {
                ret.insert(i + j);
            }
        }

        return ret;
    }

    set<string> expand(string& expr, int& index) {
        string curr_word = "";
        set<string> unique_words;
        set<string> concat_result;

        while (index < expr.size()) {
            char ch = expr[index];
            index++;

            if (ch == '{') {
                if (!curr_word.empty()) {
                    concat_result = concatenate(concat_result, curr_word);
                    curr_word = "";
                }

                auto new_words = expand(expr, index);
                concat_result = concatenate(concat_result, new_words);
            }
            else if (ch == '}') {
                if (!curr_word.empty()) {
                    concat_result = concatenate(concat_result, curr_word);
                }

                setUnion(unique_words, concat_result);
                return unique_words;
            }
            else if (ch == ',') {
                if (!curr_word.empty()) {
                    concat_result = concatenate(concat_result, curr_word);
                    curr_word = "";
                }

                setUnion(unique_words, concat_result);
                concat_result.clear();
            }
            else {
                curr_word += ch;
            }
        }

        setUnion(unique_words, concat_result);
        return unique_words;
    }
public:
    vector<string> braceExpansionII(string expression) {
        expression += '}';
        expression.insert(expression.begin(), '{');

        int index = 0;
        auto words = expand(expression, index);

        return vector<string>(words.begin(), words.end());
    }
};