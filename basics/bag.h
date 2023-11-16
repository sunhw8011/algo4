#ifndef __BAG_H_
#define __BAG_H_

typedef struct Bag Bag;

Bag* bag_init();
void bag_add(Bag *pthis, void *item);
int bag_isEmpty(Bag *pthis);
int bag_size(Bag *pthis);
void bag_delete(Bag *pthis);

#endif