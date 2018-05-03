#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cda.h"


struct cda{
	int front, back, size, capacity;
	void **array;
	void (*display)(FILE *,void *);
};

CDA *newCDA(void (*d)(FILE *,void *))
{
	CDA *myNewCDA = malloc(sizeof(CDA));
	assert(myNewCDA != 0);
	myNewCDA->front = 0;
	myNewCDA->back = 0;
	myNewCDA->size = 0;
	myNewCDA->capacity = 1;
	myNewCDA->array = malloc(sizeof(void *));
	myNewCDA->display = d;
	return myNewCDA;
}
void resize(CDA *items, int cap,int j)
{	
	void **temp = malloc(sizeof(void *) * cap);
	for(int i = j; i < items->size + j; ++i)
		temp[i] = getCDA(items,i-j);
	items->capacity = cap;
	items->array = temp;
	items->front = 0;
	items->back = items->size - 1;
}
void insertCDAfront(CDA*items, void *value)
{
	assert(value != 0);
	if(items->size ==0)
	{
		items->array[0] = value;	
		items->front = 0;
		items->back = 0;	
	}
	else 
	{
		
		if (items->size + 1 > items->capacity)
		{
			//displayCDA(stdout,items);
			int cap = items->capacity * 2;
			void **temp = malloc(sizeof(void *) * cap);
			for(int i = 0; i < items->size; ++i)
				temp[i] = getCDA(items,i);
			items->array = temp;
			items->capacity = cap;	
			items->back = items->size - 1;
			items->front = 0;
		}
		--items->front;
		if (items->front < 0)
			items->front = items->capacity - 1;
		items->array[items->front] = value;
	}
	++items->size;
	
}

void insertCDAback(CDA *items, void *value)
{
//	visualizeCDA(stdout,items);
	//printf("%d\n",items->back);
	assert(value != 0);
	if(items->size == 0)
	{
		items->array[0] = value;
		items->front = 0; 
		items->back = 0;
	}
	if(items->size > 0)
	{
		//items->array[items->back] = value;
		if (items->size + 1 > items->capacity)
		{
			int cap = items->capacity * 2;
			void **temp = malloc(sizeof(void *) * cap);
			for(int i = 0; i < items->size; ++i)
				temp[i] = getCDA(items,i);
			items->array = temp;
			items->capacity = cap;
			items->back = items->size - 1;
			items->front = 0;
		}
		++items->back;
		if(items->back == items->capacity)
			items->back = 0;
		items->array[items->back] = value;
	}
	++items->size;
}

void *removeCDAfront(CDA *items)
{
	assert(items->size >=1);
	//displayCDA(stdout,items);
	--items->size;
	void *val = items->array[items->front];
	++items->front;
	if(items->front == items->capacity) items->front = items->front - items->capacity;
	if (items->capacity > 1 && (double)items->size / items->capacity < .25)
	{
		int cap = items->capacity / 2;
		resize(items,cap,0);
	}
	//printf("\nitems size now %d\n",items->size);
	return val;
	
}

void *removeCDAback(CDA *items)
{
	assert(items->size >=1);
	--items->size;
	void *val = items->array[items->back];
	--items->back;
	if (items->back < 0) items->back = items->size + items->back;
	if(items->capacity > 1 && (double) items->size  / items->capacity < .25)
	{
		int cap = items->capacity / 2;
		resize(items,cap,0);
	}
	return val;
}

void unionCDA(CDA *recipient,CDA *donor)
{
	if(recipient->size == 0)
	{
		recipient->array = realloc(recipient->array,sizeof(void *) * donor->capacity);
		recipient->capacity = donor->capacity;
		recipient->front = donor->front;
		recipient->back = donor->back;
	}
	for (int i = 0; i < donor->size; ++i)
		insertCDAback(recipient,getCDA(donor,i));
	free(donor->array);
	donor->array = malloc(sizeof(void *));
	donor->array[0] = 0;
	donor->size = 0;
	donor->front = 0;
	donor->back = 0;
}

void *getCDA(CDA *items,int index)
{
	assert(index >= 0);
	assert(index < items->size);
	//printf("in hither");
	if (items->front > items->back)
	{
		//printf("this condition");	
	if (items->front + index < items->capacity)
			return items->array[items->front + index];
		else
			return items->array[index+items->front-items->capacity];
	}
	else
	{
		//printf("okay we go here");
		return items->array[items->front + index];
	}
}

void *setCDA(CDA *items, int index, void *value)
{
	if(index == items->size) insertCDAback(items,value);
	else items->array[index] = value;
	return items->array[index];
}

void **extractCDA(CDA *items)
{
	assert(items != 0);
	if(items->size == 0)
		return 0;
	void **temp;
	resize(items,items->size,0);
	temp = items->array;
	free(items->array);
	items->array = malloc(sizeof(void *));

	items->capacity = 1;
	items->size = 0;
	items->front = 0;
	items->back = 0;
	return temp;
}

int sizeCDA(CDA *items)
{
	return items->size;
}

void visualizeCDA(FILE *fp, CDA *items)
{
	//printf("items->size = %d\n",items->size);
fprintf(fp,"(");
	
	for(int i = 0; i < items->size; ++i)
	{
		items->display(fp,getCDA(items,i));	
		if(i+1 < items->size)
			fprintf(fp,",");
	}
	fprintf(fp,")(%d)",items->capacity - items->size);
}

void displayCDA(FILE * fp, CDA *items)
{
	//printf("front %d, back %d, capacity %d, size %d\n",items->front,items->back,items->capacity,items->size);
	//printf("items->size = %d\n",items->size);
	fprintf(fp,"(");
	
	for(int i = 0; i < items->size; ++i)
	{
		items->display(fp,getCDA(items,i));
		if (i+1 < items->size)
			fprintf(fp,",");
	}
	
	fprintf(fp,")");
}







