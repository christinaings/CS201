#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"


typedef struct Node{
	void *key;
	void *value;
	Node *right;
	Node *left;
//	void (*displayKEY)(FILE *,void *);
//ma	void (*displayVALUE)(FILE *,void *);
}Node;

typedef struct BST{
	int size;
	Node *tree;	
	int (*comparator)(void *, void *);
	void (*display)(FILE *, void *,void *);

}BST;


Node *newNode(void *key, void *value)
{
	Node *new = malloc(sizeof(Node));
	new->key = key;
	new->value = value;
	new->right = 0;
	new->left = 0;
	return new;
}

BST *newBST(void (*display)(FILE *,void *,void *),int (*comparator)(void *,void *))
{
	
	BST *MyBST = malloc(sizeof(BST));
	assert(MyBST != 0);
	//printf("here\n");
	MyBST->size = 0;
	MyBST->display = display;
	MyBST->comparator = comparator;
	//printf("here2\n");
	//printf("here3\n");
	return MyBST;
}

void insertBSTPrivate(BST *search, void *key, void *value, Node *tree)
{
	int num = search->comparator(tree->key,key);	
	if (num < 0)
	{	
		if (tree->right != 0)
			insertBSTPrivate(search,key,value,tree->right);
		else
			tree->right = newNode(key,value);
	}
	else if (num > 0)
	{	
		if (tree->left != 0)
			insertBSTPrivate(search,key,value,tree->left);
		else
			tree->left = newNode(key,value);
	}

}

void insertBST(BST *tree, void *key, void *value)
{
	
	if(tree->tree == 0)
	{
		//printf("tree is currently null\n");
		tree->tree = newNode(key,value);
	}
	else
	{
		//printf("insert2\n")
		
		insertBSTPrivate(tree, key, value, tree->tree);
	}
}

void *findBSTPrivate(BST *tree,void *key, Node *temp)
{
	if (tree->comparator(temp->key,key) < 0 && temp->right != 0)
		findBSTPrivate(tree,key,temp->right);
	else if (tree->comparator(temp->key,key) > 0 && temp->left != 0)
		findBSTPrivate(tree,key,temp->left);
	else if (tree->comparator(temp->key,key) == 0)
	{
		return temp->value;
	}
	else return 0;	
}

void *findBST(BST *tree,void *key)
{
	//printf("the key is: ");
	//displaySTRING(stdout,key);
	//printf("\n");
	if(tree->tree == 0)
		return 0;
	Node *temp = tree->tree;
	return findBSTPrivate(tree,key,temp);
}

int sizeBST(BST *tree)
{
	return tree->size;
}

void displayTREE(FILE *fp,BST *search, Node *tree)
{
	fprintf(fp,"[");
	if (tree != 0)
	{
		if (tree->left != 0)
			displayTREE(fp,search,tree->left);
	if(tree->left != 0) fprintf(fp," ");
		
	search->display(fp,tree->key,tree->value);
	if(tree->right != 0) fprintf(fp," ");
		if (tree->right != 0)
			displayTREE(fp,search,tree->right);
	}
	fprintf(fp,"]");
}

void displayBST(FILE *fp, BST *tree)
{
	
	displayTREE(fp,tree,tree->tree);
}

