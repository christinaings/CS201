#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "real.h"
#include "string.h"
#include "mystring.h"

void displayNode(FILE *fp,void *key, void *value)
{
	STRING *keyS = key;
	REAL *valR = value;
	displaySTRING(fp,keyS);
	fprintf(fp,"=");
	displayREAL(fp,valR);
}

int comparator(void *first, void *second)
{
	char *one,*two;
	one = getSTRING(first);
	two = getSTRING(second);
	return strcmp(one,two);
}

int main()
{
    printf("one\n");
    BST *myBST = newBST(displayNode,comparator);
    printf("two\n");
    insertBST(myBST,newSTRING("x"),newREAL(3.4));
    displayBST(stdout,myBST);
    insertBST(myBST,newSTRING("a"),newREAL(4));
    displayBST(stdout,myBST);
    insertBST(myBST,newSTRING("b"),newREAL(3));
    displayBST(stdout,myBST);
    insertBST(myBST,newSTRING("z"),newREAL(5));
    displayBST(stdout,myBST);
    insertBST(myBST,newSTRING("y"),newREAL(6));
    printf("after inserting\n");
    displayBST(stdout,myBST);
    printf("trying to display\n");
    return 0;
}

