#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p, s)\
    if(!((p)=malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

int main()
{
    int i, *pi;
    float f, *pf;

    pi = (int *)malloc(sizeof(int));
    pf = (float *)malloc(sizeof(float));

//    if((pi=(int *)malloc(sizeof(int)))==NULL || (pf=(float *)malloc(sizeof(float)))==NULL)
//    {
//        fprintf(stderr, "Insufficient memory");
//        exit(0);
//    }

//	MALLOC(pi, sizeof(int));
//	MALLOC(pf, sizeof(float));
    *pi = 1024; // pointer to integer
    *pf = 3.14; // pointer to float
    printf("an integer = %d, a float = %f\n", *pi, *pf);
    pf = (float *)malloc(sizeof(float));
    free(pi);
    free(pf);
}
