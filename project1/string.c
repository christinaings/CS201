#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "mystring.h"

typedef struct STRING{
    char *val;
}string;

STRING *newSTRING(char *value)
{
    STRING *newS = malloc(sizeof(STRING));
    newS->val = value;
    return newS;
}

char *getSTRING(STRING *str)
{
    return str->val;
}

STRING *setSTRING(STRING *str,void *val)
{
    char *value = val;
    str->val = value;
    return str;
}

void displaySTRING(FILE *fp,void *str)
{
    STRING *string = str;
    fprintf(fp,"%s",string->val);
}
