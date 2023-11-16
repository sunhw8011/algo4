#include <stdio.h>
#include <malloc.h>

#include "stack.h"

int main() {
    Stack *stack = stack_init();
    Iterator *itor;
    int a=1;
    int b=2;
    int c=3;

    stack_push(stack, &a);
    stack_push(stack, &b);
    stack_push(stack, &c);
    stack_push(stack, &a);

    itor = stack_iterator(stack);
    while(itor->hasNext(itor)) {
        printf("element is %d\n", *(int*)(itor->next(itor)));
    }
    printf("then\n");

    stack_pop(stack);

    itor = stack_iterator(stack);
    while(itor->hasNext(itor)) {
        printf("element is %d\n", *(int*)(itor->next(itor)));
    }
    printf("over\n");

    // 用完以后清理内存
    itor->destroy(itor);
    stack_delete(stack);

    return 0;
}