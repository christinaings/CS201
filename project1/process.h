#ifndef __VALUE_INCLUDED__
#define __VALUE_INCLUDED__

#include <stdio.h>
#include "mystring.h"
#include "bst.h"
#include "queue.h"

extern char *getType(STRING *);
extern int precedence(void *);
extern QUEUE *pfix(QUEUE *,QUEUE *);
extern REAL *process(BST *, QUEUE *);

#endif

