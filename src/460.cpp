#include "../include.h"

struct Node {
    int key;
    Node *prev, *next;
};

class LFUCache {
public:
    unordered_map<int, int> cache, key_freq;
    int cap, size;
    map<int, Node*> counter_to_keys;
    unordered_map<int, Node*> key_to_node;

    void update_freq(int key) {
        Node *cell = key_to_node[key];

        // remove key from old frequency dictionary

        // there is only one element with the specific freq
        if (cell->next == cell) {
            // counter_to_keys[key_freq[key]] = NULL;
            counter_to_keys.erase(key_freq[key]);
        }
        else {
            Node *next = cell->next;
            Node *prev = cell->prev;

            next->prev = prev;
            prev->next = next;

            // if cell is the beginning of the list
            if (cell == counter_to_keys[key_freq[key]])
                counter_to_keys[key_freq[key]] = next;
        }

        // increase frequency of key

        key_freq[key]++;

        // add key to new frequency dictonary

        if (counter_to_keys[key_freq[key]] == NULL) {
            counter_to_keys[key_freq[key]] = cell;
            cell->next = cell->prev = cell;
        }
        else {
            Node *end = counter_to_keys[key_freq[key]]->prev; // end of the list
            Node *start = end->next;

            start->prev = cell;
            end->next = cell;
            cell->next = start;
            cell->prev = end;

            counter_to_keys[key_freq[key]] = cell;
        }
    }

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (key_freq.find(key) == key_freq.end())
            return -1;
        
        update_freq(key);
    
        // return value
        return cache[key];
    }
    
    void put(int key, int value) {
        if (key_freq.find(key) == key_freq.end()) {
            Node *cell = new Node;
            cell->next = cell->prev = cell;
            cell->key = key;
            key_to_node[key] = cell;
            key_freq[key] = 0;

            if (size < cap) {
                size++;
            }
            else {
                // remove lru of the lfu
                Node *start = counter_to_keys.begin()->second;
                Node *end = start->prev;

                if (start == end) {
                    counter_to_keys.erase(counter_to_keys.begin());
                }
                else {
                    Node *u = end->prev;
                    u->next = start;
                    start->prev = u;
                }

                key_freq.erase(end->key);
                key_to_node.erase(end->key);
                cache.erase(end->key);

                delete end;
            }

            // at slot 0 there should only be one cell at a time
            counter_to_keys[0] = cell;
        }

        update_freq(key);
 
        // update value
        cache[key] = value;
    }
};