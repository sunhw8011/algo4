#include <malloc.h>

#include "bag.h"

typedef struct {
    void *item;
    Node *next;
} Node;

struct Bag
{
    Node *first;
    int N;
};

Bag* bag_init() {
    Bag *pthis = (Bag*)malloc(sizeof(Bag));
    pthis->first = NULL;
    pthis->N = 0;
    return pthis;
}

// 采用头插法添加元素
void bag_add(Bag *pthis, void *item) {
    Node *oldfirst = pthis->first;
    pthis->first = (Node*)malloc(sizeof(Node));
    pthis->first->item = item;
    pthis->first->next = oldfirst;
    pthis->N += 1;
}

int bag_isEmpty(Bag *pthis) {
    return pthis->first == NULL;
}

int bag_size(Bag* pthis) {
    return pthis->N;
}

void bag_delete(Bag *pthis) {
    Node *first = pthis->first;
    while(first != NULL) {
        Node *tmp = first;
        first = first->next;
        free(tmp);
    }
    free(pthis);
}
