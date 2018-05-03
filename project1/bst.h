#ifndef __BST_INCLUDED__
#define __BST_INCLUDED__

#include <stdio.h>

typedef struct Node Node;
typedef struct BST BST;

extern void displayNode(FILE *fp,void *key, void *value);
extern BST *newBST(void (*display)(FILE *,void *,void *),int (*comparator)(void *,void *));
extern void insertBST(BST *,void *,void *);
extern void *findBST(BST *,void *);
extern int sizeBST(BST *);
extern void displayBST(FILE *,BST *);

#endif

