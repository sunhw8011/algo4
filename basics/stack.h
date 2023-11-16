#ifndef __STACK_H_
#define __STACK_H_

#include "iterator.h"

typedef struct Stack Stack;

Stack* stack_init();
void stack_push(Stack *pthis, void *item);
void* stack_pop(Stack *pthis);
int stack_isEmpty(Stack *pthis);
int stack_size(Stack *pthis);
void stack_delete(Stack *pthis);

Iterator* stack_iterator(Stack *pthis);

#endif