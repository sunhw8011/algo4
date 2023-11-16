CC = gcc
CFLAGS = -g -Wall -m64

testStack: stack.o testStack.o
	$(CC) $(CFLAGS) stack.o testStack.o -o testStack

testStack.o: stack.h testStack.c
	$(CC) $(CFLAGS) testStack.c -c

main: main.o bag.o
	$(CC) $(CFLAGS) main.o bag.o -o main

main.o: main.c bag.h
	$(CC) $(CFLAGS) main.c -c

# 背包的编译项
bag.o: bag.h bag.c
	$(CC) $(CFLAGS) bag.c -c

# 下压栈的编译项
stack.o: stack.h stack.c iterator.h
	$(CC) $(CFLAGS) stack.c -c

clean:
	rm -f *.o
	rm -f *.h.gch
	rm -f testStack