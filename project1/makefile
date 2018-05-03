OBJS = string.o real.o da.o stack.o cda.o queue.o scanner.o bst.o process.o matilda.o
OPTS = -Wall -Wextra -g -std=c99

test-all: test-bst matilda

test: test-bst matilda
	./test-bst
	./matilda -i -b testvar

matilda:  $(OBJS)
	gcc $(OPTS) $(OBJS) -lm -o matilda

matilda.o: matilda.c scanner.h queue.h stack.h process.h mystring.h
	gcc $(OPTS) -c matilda.c

process.o: process.c real.h bst.h queue.h stack.h process.h mystring.h
	gcc $(OPTS) -c process.c

test-bst: bst.o testBST.o string.o real.o
	gcc $(OPTS) bst.o testBST.o string.o real.o -o test-bst

testBST.o: testBST.c real.h mystring.h bst.h
	gcc $(OPTS) -c testBST.c

bst.o: bst.c bst.h real.h
	gcc $(OPTS) -c bst.c

scanner.o: scanner.c scanner.h
	gcc $(OPTS) -c scanner.c

queue.o: queue.c cda.h queue.h
	gcc $(OPTS) -c queue.c

cda.o: cda.c cda.h
	gcc $(OPTS) -c cda.c
	
stack.o: stack.c stack.h da.h
	gcc $(OPTS) -c stack.c

da.o : da.c da.h
	gcc $(OPTS) -c da.c

real.o: real.c real.h
	gcc $(OPTS) -c real.c

string.o: string.c mystring.h
	gcc $(OPTS) -c string.c

clean: 
	rm -f $(OBJS) testBST.o test-bst
	rm -f string.o matlida.o cda.o real.o queue.o da.o stack.o scanner.o bst.o
	rm -f matilda

