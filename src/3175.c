#include <stdlib.h>

// Overcomplicated

typedef struct Node Node;
struct Node {
    int player, skill, won;
    Node *next, *prev;
};

typedef struct {
    Node *begin, *end;
} Deque;

void insertBack(Deque *dq, int p, int s, int w) {
    Node *aux = malloc(sizeof(Node));
    aux->player = p;
    aux->skill = s;
    aux->won = w;

    if (dq->begin == NULL) {
        dq->begin = dq->end = aux;
        aux->next = aux->prev = NULL;
    }
    else {
        dq->end->next = aux;
        aux->next = NULL;
        aux->prev = dq->end;
        dq->end = aux;
    }
}

void insertFront(Deque *dq, int p, int s, int w) {
    Node *aux = malloc(sizeof(Node));
    aux->player = p;
    aux->skill = s;
    aux->won = w;

    if (dq->begin == NULL) {
        dq->begin = dq->end = aux;
        aux->next = aux->prev = NULL;
    }
    else {
        dq->begin->prev = aux;
        aux->next = dq->begin;
        aux->prev = NULL;
        dq->begin = aux;
    }
}

void popBack(Deque *dq, int *p, int *s, int *w) {
    if (dq->begin == dq->end) {
        *p = dq->begin->player;
        *s = dq->begin->skill;
        *w = dq->begin->won;

        free(dq->begin);
        dq->begin = dq->end = NULL;

        return;
    }

    *p = dq->end->player;
    *s = dq->end->skill;
    *w = dq->end->won;

    Node *aux = dq->end;
    dq->end = dq->end->prev;
    dq->end->next = NULL;
    free(aux);
}

void popFront(Deque *dq, int *p, int *s, int *w) {
    if (dq->begin == dq->end) {
        *p = dq->begin->player;
        *s = dq->begin->skill;
        *w = dq->begin->won;

        free(dq->begin);
        dq->begin = dq->end = NULL;

        return;
    }

    *p = dq->begin->player;
    *s = dq->begin->skill;
    *w = dq->begin->won;

    Node *aux = dq->begin;
    dq->begin = dq->begin->next;
    dq->begin->prev = NULL;
    free(aux);
}

int findWinningPlayer(int* skills, int n, int k) {
    int most_skilled = 0, m = 0;

    Deque dq;
    dq.begin = dq.end = NULL;

    for (int i = 0; i < n; i++) {
        insertBack(&dq, i, skills[i], 0);

        if (skills[i] > m) {
            most_skilled = i;
            m = skills[i];
        }
    }

    if (k >= n)
        return most_skilled;

    while (1) {
        int p1, s1, w1, p2, s2, w2;
        popFront(&dq, &p1, &s1, &w1);
        popFront(&dq, &p2, &s2, &w2);

        if (w1 == k)
            return p1;
        if (w2 == k)
            return p2;

        if (s1 > s2) {
            insertFront(&dq, p1, s1, w1 + 1);
            insertBack(&dq, p2, s2, w2);
        }
        else {
            insertFront(&dq, p2, s2, w2 + 1);
            insertBack(&dq, p1, s1, w1);
        }
    }

    return -1;
}