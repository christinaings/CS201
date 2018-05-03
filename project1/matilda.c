#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"
#include "real.h"
#include "scanner.h"
#include "process.h"
#include "bst.h"
#include "mystring.h"
#include "queue.h"
#include "stack.h"


void displayNode(FILE *fp,void *key, void *value)
{
	STRING *keyS = key;
	REAL *valR = value;
	displaySTRING(fp,keyS);
	fprintf(fp,"=");
	displayREAL(fp,valR);
}

void pOutput(QUEUE *Q)
{
    //int size = sizeQUEUE(Q);
    STRING *temp;

    for (int i = 0; i < sizeQUEUE(Q); ++i)
    {
        temp = dequeue(Q);
        displaySTRING(stdout,temp);
	enqueue(Q,temp);
	if (i + 1 < sizeQUEUE(Q))
		fprintf(stdout," ");
    }
    fprintf(stdout,"\n");
}
void iOutput(QUEUE *Q)
{
	//int size = sizeQUEUE(Q);
	STRING *temp;
	//printf("iOutput sizeQUEUE %d",sizeQUEUE(Q));
	for(int i = 0; i < sizeQUEUE(Q); ++i)
	{
		
		//printf("why do we segfault\n");
		temp = dequeue(Q);
		displaySTRING(stdout,temp);
        	if(strcmp(getSTRING(temp),";") == 0)
            		fprintf(stdout,"\n");
        	else if (i < sizeQUEUE(Q))
			fprintf(stdout," ");
		enqueue(Q,temp);
	}
}

int comparator(void *first, void *second)
{
	int comp = strcmp(getSTRING(first),getSTRING(second));
	//printf("%d\n",comp);
	return comp;
}

int main(int argc,char **argv)
{
    assert(argc > 1);
    int i = 0, b = 0, p = 0;
    for(int j = 0; j < argc; ++j)
    {
        if(strcmp(argv[j],"-v") == 0)
        {
            printf("Christina Alexander\n");
            exit(1);
        }
        else if(strcmp(argv[j],"-i") == 0)
            i = 1;
        else if (strcmp(argv[j],"-b") == 0)
            b = 1;
        else if (strcmp(argv[j],"-p") == 0)
            p = 1;
    }
    
    FILE *in;
    in = fopen(argv[argc-1],"r");
    char *token;
    QUEUE *input;
    input = newQUEUE(displaySTRING);
    token = readToken(in);
   
    QUEUE *expr;
    expr = newQUEUE(displaySTRING);
    
    BST *vars = newBST(displayNode,comparator);
    STRING *temp,*temp2;

    while(token != 0)
    {
        STRING *newIn;
        newIn = newSTRING(token);
        //displaySTRING(stdout,newIn);
        enqueue(input,newIn);
        if (strcmp(getSTRING(newIn),"var") == 0)
        {
            //printf("well then it must be going here!\n");
            temp = newSTRING(readToken(in));
            enqueue(input,temp);
            readToken(in);
            enqueue(input,newSTRING("="));
            temp2 = newSTRING(readToken(in));
            enqueue(input,temp2);
            REAL *val = newREAL(atof(getSTRING(temp2)));
            insertBST(vars,temp,val);
            readToken(in);
            enqueue(input,newSTRING(";"));
        //	displayBST(stdout,vars);
	}
        else if (strcmp(getSTRING(newIn),"var") != 0 && strcmp(getSTRING(newIn),";") != 0)
        {
            enqueue(expr,newSTRING(token));
        }

        token = readToken(in);
    
    }
   QUEUE *postFix = newQUEUE(displaySTRING);
   if (i == 1)
        iOutput(input);
   postFix = pfix(expr,postFix);
   QUEUE *tempQ = newQUEUE(displaySTRING);
   tempQ = postFix;
   if (p == 1)
 	pOutput(tempQ); 
//	displayQUEUE(stdout,postFix);
   if (b == 1)
    {
//	printf("does it happen here?");
        displayBST(stdout,vars);
        printf("\n");
    }
    REAL *result = process(vars,postFix);
    displayREAL(stdout,result);
    printf("\n");

    return 0;
}

