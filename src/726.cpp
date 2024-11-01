#include "../include.h"

class Solution {
public:
    int i = 0;

    // (Mg(OH)2)

    unordered_map<string, int> process_formula(string& formula) {
        unordered_map<string, int> ret;
        string atom = "", count = "";

        while (i < formula.size()) {
            const char& ch = formula[i];

            if (ch == '(') {
                i++;
                auto tmp = process_formula(formula);

                for (auto& [k, v] : tmp) {
                    ret[k] += v;
                }
            }
            else if (isupper(ch)) {
                if (count == "") count = "1";
                if (atom != "") ret[atom] += stoi(count);

                atom = ch;
                count = "";

                i++;
            }
            else if (islower(ch)) {
                atom += ch;
                i++;
            }
            else if (isdigit(ch)) {
                count += ch;
                i++;
            }
            else {
                if (count == "") count = "1";
                if (atom != "") ret[atom] += stoi(count);

                i++;
                
                int m = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    m = m * 10 + (formula[i] - '0');
                    i++;
                }

                if (m) {
                    for (auto& [k, v] : ret) {
                        ret[k] = v * m;
                    }
                }

                return ret;
            }
        }

        if (count == "") count = "1";
        if (atom != "") ret[atom] += stoi(count);

        return ret;
    }

    string countOfAtoms(string formula) {
        auto res = process_formula(formula);
        map<string, int> atoms_count(res.begin(), res.end());

        string answer = "";
        for (auto& [atom, count] : atoms_count) {
            answer += (atom + (count == 1 ? "" : to_string(count)));
        }

        return answer;
    }
};