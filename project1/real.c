#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "real.h"

struct REAL
    {
    double store;
    };


/******************* public interface *********************/

REAL *
newREAL(double v)
    {
    REAL *p = malloc(sizeof(REAL));
    assert(p != 0);
    p->store = v;
    return p;
    }

double
getREAL(REAL *r)
    {
    return r->store;
    }

void
setREAL(REAL *r, double v)
    {
    r->store = v;
    }

void
displayREAL(FILE *fp, void *p)
    {
    REAL *r = p;
    fprintf(fp, "%f", r->store);
    }






