#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "integer.h"
#include "real.h"
#include "string.h"

int
main(void)
    {
    printf("DA tester: 0,5\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-0-5.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(985));
    insertDA(d,newINTEGER(665));
    insertDA(d,newINTEGER(285));
    insertDA(d,newINTEGER(43));
    insertDA(d,newINTEGER(778));
    displayDA(stdout,d);
    INTEGER *temp = getDA(d,0);
    setDA(d,0,getDA(d,sizeDA(d)-1));
    setDA(d,sizeDA(d)-1,temp);
    displayDA(stdout,d);
    printf("\n");
    return 0;
    }
