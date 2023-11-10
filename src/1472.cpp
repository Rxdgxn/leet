#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class BrowserHistory {
public:
    struct Tab {
        string url;
        Tab *next;
        Tab *prev;
    } *curr_tab = new Tab;

    BrowserHistory(string homepage) {
        curr_tab->url = homepage;
        curr_tab->next = NULL;
        curr_tab->prev = NULL;
    }
    
    void visit(string url) {
        Tab *t = new Tab;
        t->url = url;
        t->next = NULL;
        t->prev = curr_tab;

        curr_tab->next = t;
        curr_tab = t;
    }
    
    string back(int steps) {
        while (steps > 0 && curr_tab->prev != NULL) {
            steps--;
            curr_tab = curr_tab->prev;
        }

        return curr_tab->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && curr_tab->next != NULL) {
            steps--;
            curr_tab = curr_tab->next;
        }

        return curr_tab->url;
    }
};