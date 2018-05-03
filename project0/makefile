OBJS = da.o stack-test-0-2.o stack.o real.o
OPTS = -Wall -Wextra -std=c99

test: test-cda1 test-cda2 test-cda3 test-cda4 test-cda5 test-cda6

queue.o: queue.c queue.h cda.h
	gcc $(OPTS) -c queue.c

test-cda1: cda.o cda-test-2-4.o integer.o
	gcc $(OPTS) cda.o cda-test-2-4.o integer.o -o test-cda1

test-cda2: cda.o cda-test-2-5.o integer.o
	gcc $(OPTS) cda.o cda-test-2-5.o integer.o -o test-cda2

test-cda3: cda.o cda-test-2-7.o integer.o
	gcc $(OPTS) cda.o cda-test-2-7.o integer.o -o test-cda3

test-cda4: cda.o cda-test-2-8.o integer.o
	gcc $(OPTS) cda.o cda-test-2-8.o integer.o -o test-cda4

test-cda5: cda.o cda-test-2-9.o integer.o
	gcc $(OPTS) cda.o cda-test-2-9.o integer.o -o test-cda5

test-cda6: cda.o cda-test-2-10.o integer.o
	gcc $(OPTS) cda.o cda-test-2-10.o integer.o -o test-cda6

cda-test-2-4.o: cda-test-2-4.c cda.h integer.h
	gcc $(OPTS) -c cda-test-2-4.c

cda-test-2-5.o: cda-test-2-5.c cda.h integer.h
	gcc $(OPTS) -c cda-test-2-5.c

cda-test-2-7.o: cda-test-2-7.c cda.h integer.h
	gcc $(OPTS) -c cda-test-2-7.c

cda-test-2-8.o: cda-test-2-8.c cda.h integer.h
	gcc $(OPTS) -c cda-test-2-8.c

cda-test-2-9.o: cda-test-2-9.c cda.h integer.h
	gcc $(OPTS) -c cda-test-2-9.c

cda-test-2-10.o: cda-test-2-10.c cda.h integer.h
	gcc $(OPTS) -c cda-test-2-10.c

cda.o: cda.c cda.h
	gcc $(OPTS) -c cda.c
	
stack.o: stack.c stack.h da.h
	gcc $(OPTS) -c stack.c

da-test-0-3.o: da-test-0-3.c da.h integer.h
	gcc $(OPTS) -c da-test-0-3.c

integer.o : integer.c integer.h
	gcc $(OPTS) -c integer.c

da.o : da.c da.h
	gcc $(OPTS) -c da.c

real.o: real.c real.h
	gcc $(OPTS) -c real.c

clean: 
	rm -f $(OBJS)
	rm -f cda.o test-queue.o queue.o test-cda.o test-da.o
	rm -f test-da test-queue test-stack test-cda
