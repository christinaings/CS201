#ifndef __STRING_INCLUDED__
#define __STRING_INCLUDED__

#include <stdio.h>
typedef struct STRING STRING;

extern STRING *newSTRING(char *);
extern char *getSTRING(STRING *r);
extern STRING *setSTRING(STRING *r, void *n);
extern void displaySTRING(FILE *fp, void *p);

#endif
