#include <malloc.h>

#include "stack.h"

// 链表节点
typedef struct Node Node;
typedef struct Node{
    void *item;
    Node *next;
} Node;

struct Stack {
    Node *first;
    int N;
};

// 迭代器
typedef struct
{
    Iterator implement;  // 注意，这里不是指针
    Node *current;
} ListIterator;

Stack* stack_init() {
    Stack *pthis = (Stack*)malloc(sizeof(Stack));
    pthis->first = NULL;
    pthis->N = 0;
    return pthis;
}

// 默认链表头为栈顶，采用头插法
void stack_push(Stack *pthis, void *item) {
    Node *oldfirst = pthis->first;
    pthis->first = (Node*)malloc(sizeof(Node));
    pthis->first->item = item;
    pthis->first->next = oldfirst;
    pthis->N += 1;
}

void* stack_pop(Stack *pthis) {
    if (stack_isEmpty(pthis)) {
        return NULL;
    }
    void *result = pthis->first->item;
    pthis->first = pthis->first->next;
    pthis->N -= 1;
    return result;
}

int stack_isEmpty(Stack *pthis) {
    return pthis->first == NULL;
}

int stack_size(Stack *pthis) {
    return pthis->N;
}

void stack_delete(Stack *pthis) {
    Node *first = pthis->first;
    while(first != NULL) {
        Node *tmp = first;
        first = first->next;
        free(tmp);
    }
    free(pthis);
}

// 迭代器函数实现
int stack_itor_hasNext(Iterator *pthis) {
    return ((ListIterator*)pthis)->current != NULL;
}

void* stack_itor_next(Iterator *pthis) {
    void *result = ((ListIterator*)pthis)->current->item;
    ((ListIterator*)pthis)->current = ((ListIterator*)pthis)->current->next;
    return result;
}
void stack_itor_remove(Iterator *pthis) {

}

void stack_itor_destroy(Iterator *pthis) {
    free((ListIterator*)pthis);
}

// 获取一个新的迭代器
Iterator* stack_iterator(Stack *pthis) {
    ListIterator *itor = (ListIterator*)malloc(sizeof(ListIterator));
    itor->current = pthis->first;

    // 把函数指针对应上
    itor->implement.hasNext = stack_itor_hasNext;
    itor->implement.next = stack_itor_next;
    itor->implement.remove = stack_itor_remove;
    itor->implement.destroy = stack_itor_destroy;

    return (Iterator*)itor;
}

