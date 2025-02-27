#include "../include.h"

struct Node {
    int key, val;
    Node *next, *prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, Node*> keys_map;
    int limit;

    Node *begin = nullptr, *end = nullptr;

    LRUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        if (keys_map.find(key) == keys_map.end()) return -1;

        Node *n = keys_map[key];

        if (n == begin) return n->val;

        if (n == end) {
            n->prev->next = nullptr;
            end = n->prev;
            n->prev = nullptr;
            n->next = begin;

            begin->prev = n;
            begin = n;

            return n->val;
        }

        n->prev->next = n->next;
        n->next->prev = n->prev;

        n->prev = nullptr;
        n->next = begin;

        begin->prev = n;
        begin = n;

        return n->val;
    }
    
    void put(int key, int value) {
        if (keys_map.find(key) != keys_map.end()) {
            int _ = get(key);
            keys_map[key]->val = value;

            return;
        }

        if (keys_map.size() == limit) {
            if (begin == end) {
                keys_map.erase(end->key);
                
                begin->key = key;
                begin->val = value;
                
                keys_map.insert({key, end});

                return;
            }
            
            Node *tmp = end->prev;
            keys_map.erase(end->key);

            end->prev->next = nullptr;
            end->prev = nullptr;

            assert(tmp != nullptr);

            end->next = begin;
            begin->prev = end;

            begin = end;
            end = tmp;

            begin->key = key;
            begin->val = value;

            keys_map.insert({key, begin});

            return;
        }

        Node *n = new Node(key, value);
        keys_map.insert({key, n});

        if (begin == nullptr) {
            begin = end = n;
            return;
        }

        n->next = begin;
        begin->prev = n;

        begin = n;
    }
};