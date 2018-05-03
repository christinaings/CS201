#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "da.h"

struct stack{
	DA *myStack;
	void (*display)(FILE *,void *);
};

STACK *newSTACK(void (*d)(FILE *,void *))
{
	STACK *newStack = malloc(sizeof(STACK));
	assert(newStack != 0);
	newStack->myStack = newDA(d);
	newStack->display = d;
	return newStack;
}

void push(STACK *items,void *value)
{
	insertDA(items->myStack,value);
}

void *pop(STACK *items)
{
	assert(sizeSTACK(items) > 0);
	void *val = removeDA(items->myStack);
	return val;
}

void *peekSTACK(STACK *items)
{
	assert(sizeSTACK(items) > 0);
	void *val = getDA(items->myStack,sizeDA(items->myStack) - 1);
	return val;
}

int sizeSTACK(STACK *items)
{
	return sizeDA(items->myStack);
}

void displaySTACK(FILE *fp,STACK *items)
{
	fprintf(fp,"|");
	for (int i = sizeDA(items->myStack) - 1; i >= 0; --i)
	{
		if (getDA(items->myStack,i) == 0) break;
		items->display(fp,getDA(items->myStack,i));
		if (i - 1 >= 0)
			fprintf(fp,",");
	}
	fprintf(fp,"|");
}

void visualizeSTACK(FILE *fp,STACK *items)
{
	displayDA(fp,items->myStack);
}
