#ifndef __ITERATOR_H_
#define __ITERATOR_H_

typedef struct Iterator Iterator;
struct Iterator
{
    int (*hasNext)(Iterator *pthis);
    void* (*next)(Iterator *pthis);
    void (*remove)(Iterator *pthis);
    void (*destroy)(Iterator *pthis);  // 用delete更直观。为什么不用呢？怪vscode
};

#endif
