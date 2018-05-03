#include <stdio.h>
typedef struct REAL REAL;

extern REAL *newREAL(double r);
extern double getReal(REAL *r);
extern void setREAL(REAL *r, double n);
extern void displayREAL(FILE *fp, void *p);

