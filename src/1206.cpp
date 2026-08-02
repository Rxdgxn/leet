#include "../include.h"

class Skiplist {
public:
    struct Node {
        int value;
        Node *next, *prev;
        Node *lower;
    };

    #define NUM_LAYERS 8 // magic number after a few submissions
    Node* layers[NUM_LAYERS]; // layers[0] is the bottom one

    Skiplist() {    
        Node *prev = nullptr;

        // There should be no need for setting prev pointers to the original list sentinels
        for (int i = 0; i < NUM_LAYERS; i++) {
            layers[i] = new Node;
            layers[i]->next = nullptr;
            layers[i]->lower = prev;

            prev = layers[i];
        }
    }
    
    bool search(int target) {
        return search_layer(layers[NUM_LAYERS - 1], NUM_LAYERS - 1, target) != nullptr;
    }

    Node* search_layer(Node *base, int layer, int target) {
        // base is actually a sentinel, even if it contains meaningful information or not
        // check image on wikipedia

        if (layer < 0)
            return nullptr;

        if (base->next == nullptr)
            return search_layer(base->lower, layer - 1, target);

        Node *it = base->next;

        while (it->next != nullptr) {
            if (it->value >= target)
                break;

            it = it->next;
        }

        if (it->value == target)
            return it;

        if (it->value < target)
            return search_layer(it->lower, layer - 1, target);

        return search_layer(it->prev->lower, layer - 1, target);
    }
    
    void add(int num) {
        int layer = NUM_LAYERS - 1;
        Node* predecesors[NUM_LAYERS]; // "sentinels"

        Node *it = layers[layer];

        while (layer >= 0) {
            while (it->next != nullptr && it->next->value < num)
                it = it->next;

            predecesors[layer] = it;
            layer--;

            it = it->lower;
        }

        layer = 0;
        Node *low = nullptr;

        do {
            Node *p = predecesors[layer];
            Node *n = p->next;

            Node *new_node = new Node;
            new_node->value = num;
            new_node->lower = low;
            new_node->prev = p;
            new_node->next = n;

            p->next = new_node;
            if (n != nullptr)
                n->prev = new_node;

            layer++;
            low = new_node;
        } while (layer < NUM_LAYERS && rand() % 2);
    }
    
    bool erase(int num) {
        Node *found = search_layer(layers[NUM_LAYERS - 1], NUM_LAYERS - 1, num);

        if (found == nullptr)
            return false;

        Node *it = found;
        while (it != nullptr) {
            Node *p = it->prev;
            Node *n = it->next;

            p->next = n;

            if (n != nullptr)
                n->prev = p;

            Node *old = it;
            it = it->lower;
            delete old;
        }

        return true;
    }
};