#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <assert.h>
#include "queue.h"
#include "cda.h"

typedef struct queue{
	CDA *myCDA;
	void (*display)(FILE *,void *);
}QUEUE;

QUEUE *newQUEUE(void (*d)(FILE *,void *))
{
	QUEUE *myNewQ = malloc(sizeof(QUEUE));
	assert(myNewQ != 0);
	myNewQ->myCDA = newCDA(d);
	myNewQ->display = d;
	return myNewQ;
}

void enqueue(QUEUE *items,void *value)
{
	//printf("are we even going here?");
	insertCDAback(items->myCDA,value);
	//displayQUEUE(stdout,items);
}

void *dequeue(QUEUE *items)
{
	if(sizeCDA(items->myCDA) == 0) return 0;
	void *val = removeCDAfront(items->myCDA);
	return val;
}

void *peekQUEUE(QUEUE *items)
{
	assert(sizeCDA(items->myCDA) > 0);
	void *val = getCDA(items->myCDA,0);
	return val;
}

int sizeQUEUE(QUEUE *items)
{
	int size =sizeCDA(items->myCDA);
	return size;
}
void displayQUEUE(FILE *fp,QUEUE *items)
{
	fprintf(fp,"<");
	for(int i = 0; i < sizeCDA(items->myCDA); ++i)
	{
		if(getCDA(items->myCDA,i) == 0) break;
		items->display(fp,getCDA(items->myCDA,i));
		if (i + 1 < sizeCDA(items->myCDA))
			fprintf(fp,",");
	}
	fprintf(fp,">");
	
}


void visualizeQUEUE(FILE *fp,QUEUE *items)
{
	displayCDA(fp,items->myCDA);
}





