#include <assert.h>
#include <stdlib.h>
#include "da.h"

struct da{
	int capacity;
	int spacesTaken;
	void **array;
	void (*display)(FILE *,void *);
};

DA *newDA(void (*display)(FILE *fp,void *item))
{
	DA *myNewDA = malloc(sizeof(DA));
	assert(myNewDA != 0);
	myNewDA->capacity = 1;
	myNewDA->spacesTaken = 0;
	myNewDA->array = malloc(sizeof(void *));
	myNewDA->display = display;
	return myNewDA;
}
//use realloc you dummy.
void insertDA(DA *items, void *value)
{
	assert(items != 0);
	if (items->spacesTaken == items->capacity)
	{
		items->capacity = items->capacity * 2;
		items->array = realloc(items->array,sizeof(void *) * items->capacity);	
	}
	items->array[items->spacesTaken] = value;
	++items->spacesTaken;
	
}

void *removeDA(DA *items)
{
	assert(items->spacesTaken > 0);
	void *temp = malloc(sizeof(void));
	temp = items->array[items->spacesTaken -1];
	items->array[items->spacesTaken -1] = 0;
	--items->spacesTaken;
		
	if (((double)items->spacesTaken/items->capacity) < .25 && items->capacity != 1)
	{
		int cap = items->capacity / 2;
		items->array = realloc(items->array,sizeof(void *) * cap);
		items->capacity = cap;
	}
	return temp;
}

void unionDA(DA *recipient, DA *donor)
{
	int size = donor->spacesTaken;
	for (int i = 0; i < donor->spacesTaken; ++i)
		insertDA(recipient,donor->array[i]);
	for (int i = 0; i < size; ++i)
		removeDA(donor);	
}

void *getDA(DA *items,int index)
{
	assert(index >= 0 && index < items->capacity);
	return items->array[index];
}

void *setDA(DA *items,int index,void *value)
{
	assert(index >= -1 && index <= items->spacesTaken);
	if (index == items->spacesTaken)
		insertDA(items, value);
	else
		items->array[index] = value;
	return items->array[index];
}
//redo this because it looks stupid.
void **extractDA(DA *items)
{
	assert(items != 0);
	if (items->spacesTaken == 0)
		return 0;
	void **tempArray= realloc(items->array,sizeof(void *) * items->spacesTaken);
	//free(items->array);
	items->array = malloc(sizeof(void *));
	items->capacity = 1;
	items->spacesTaken = 0;
	return tempArray;
}

int sizeDA(DA *items)
{
	return items->spacesTaken;
}

void visualizeDA(FILE *fp, DA *items)
{
	displayDA(fp,items);
	fprintf(fp,"[%i]",(items->capacity - items->spacesTaken));
}

void displayDA(FILE *fp, DA *items)
{
	fprintf(fp,"[");
	for (int i = 0; i < items->spacesTaken; ++i)
	{
		if (items->array[i] == 0) break;
		items->display(fp,items->array[i]);
		if (i < items->spacesTaken - 1)
			fprintf(fp,",");
	}
	fprintf(fp,"]");
}

