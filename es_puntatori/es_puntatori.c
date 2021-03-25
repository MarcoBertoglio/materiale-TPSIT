/*
Author: Bertoglio Marco
Date :
es :
*/
#include <stdlib.h>
#include <stdio.h>

main(){
    int *pi;
    *pi = 15;
    pi=pi+1;
    *pi = 20;
    printf("%p\n", pi);
    printf("%d", pi);

	printf("\n premi un tasto per uscire");
	getch();
}
