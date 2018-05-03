#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "mystring.h"
#include "string.h"
#include "bst.h"
#include "queue.h"
#include "stack.h"
#include "real.h"
#include "process.h"

char *getType(STRING *one)
{
    //printf("getting type for string: ");
    //displaySTRING(stdout,one);
    //printf("\n");
    char *get = getSTRING(one);
    if ((get[0] >= 'a' && get[0] <= 'z') || (get[0] >= 'A' && get[0] <= 'Z'))
        return "VARIABLE";
    else if ((get[0] >= '0' && get[0] <= '9')|| (get[0] == '-' && strlen(get) > 1) || get[0] == '.')
        return "NUMBER";
    else
        return "OPERATOR";
}

int precedence(void *string)
{
	//go back through and replace with comparator function
	char *value = getSTRING(string);
	if (strcmp(value,"+") == 0)
		return 1;
	else if (strcmp(value,"-") == 0)
		return 2;
	else if (strcmp(value,"*") == 0)
		return 3;
	else if (strcmp(value,"/") == 0)
		return 4;
	else if (strcmp(value,"%") == 0)
		return 5;
	else if (strcmp(value,"^") == 0)
		return 6;
	else if (strcmp(value,"(") == 0)
		return 7;
	else if (strcmp(value,")") == 0)
		return 8;
	return -1;
}

QUEUE *pfix(QUEUE *in,QUEUE *out)
{
    //printf("whyyyy");
    STRING *temp;
    char *tempStr;
    STACK *pofix = newSTACK(displaySTRING);
    //int addPrec = 0;
    //displayQUEUE(stdout,in);
    while(sizeQUEUE(in) > 0)
    {
	temp = dequeue(in);
	tempStr = getSTRING(temp);
	if(strcmp(getType(temp),"NUMBER") == 0 || strcmp(getType(temp),"VARIABLE") == 0)
		enqueue(out,temp);
	else
	{
		if (precedence(temp) < 7)
		{
		while (sizeSTACK(pofix) > 0 && precedence(peekSTACK(pofix)) >= precedence(temp)
			&& precedence(peekSTACK(pofix)) != 7)
			enqueue(out,pop(pofix));
			push(pofix,temp);
		}
		if(strcmp(tempStr,"(") == 0)
			push(pofix,temp);
		else if (strcmp(tempStr,")") == 0)
		{
			while (sizeSTACK(pofix) > 0 && precedence(peekSTACK(pofix)) != 7)
				enqueue(out,pop(pofix));
			if (sizeSTACK(pofix) > 0 && precedence(peekSTACK(pofix)) == 7)
				pop(pofix);
		}
	
    	}
    }
    while(sizeSTACK(pofix) > 0)
    {
        //printf("final pop\n");
	temp = pop(pofix);
        enqueue(out,temp);
    }
	//displayQUEUE(stdout,out);
    return out;
}

REAL *process(BST *search, QUEUE *post)
{
    STACK *result = newSTACK(displayREAL);
    STRING *myVal;
    REAL *num;
    char *type;
    //printf("here\n");
   // displayQUEUE(stdout,post);
    while(sizeQUEUE(post) > 0)
    {
        myVal = dequeue(post);
        type = getType(myVal);
        if (strcmp(type,"NUMBER") == 0 )
        {
            double val = atof(getSTRING(myVal));
            num = newREAL(val);
            push(result,num); 
        }
        else if (strcmp(type,"VARIABLE") == 0 && search != 0)  
        {
	    REAL *temp = findBST(search,myVal);
	    if(temp == 0)
            {
                printf("variable %s was not declared\n",getSTRING(myVal));
                exit(1);
            }
	    push(result,temp);
	    
        }
        else if (strcmp(type,"OPERATOR") == 0 && sizeSTACK(result) > 1)
        {       
                REAL *temp1;
                double one,two;
                one = getREAL(pop(result));
                two = getREAL(pop(result));
            
                if (strcmp(getSTRING(myVal),"+") == 0)
                    temp1 = newREAL(two + one);
                else if(strcmp(getSTRING(myVal),"-") == 0)
                    temp1 = newREAL(two - one);
                else if (strcmp(getSTRING(myVal),"*") == 0)
                { 
                    temp1 = newREAL(two * one);
                }
                else if (strcmp(getSTRING(myVal),"/") == 0)
                    temp1 = newREAL(two / one);
                else if (strcmp(getSTRING(myVal),"^") == 0)
          	    temp1 = newREAL(pow(two,one));
                  
		else if(strcmp(getSTRING(myVal),"%") == 0)
                    temp1 = newREAL(fmod(two,one));
                push(result,temp1);
                
        }
    }
    //printf("we exit");
    REAL *final = pop(result);
    return final;
}





