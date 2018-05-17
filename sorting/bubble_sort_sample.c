/*Write a Program to implement Bubble Sort using array.*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(int argc, char const *argv[])
{
	system("clear");
	int n, lower, upper;
	printf("\nEnter array size : ");
	scanf("%d",&n);
	int ar[n];
	printf("\nEnter lower bound : ");
	scanf("%d",&lower);
	printf("\nEnter upper bound : ");
	scanf("%d",&upper);

	for (int i = 0; i < n; ++i)
		ar[i]=rand()%(upper-lower+1)+lower;

	for (int i = 0; i < n; ++i)
		printf("\n%d",ar[i]);

	printf("\nSorting Array...!");
	for (int i = 0; i < n-1; i++) 
   	for ( int j = 0; j < n-i-1; j++) 
       	if (ar[j] > ar[j+1])
        	swap(&ar[j], &ar[j+1]);
     printf("\nSorted Array is");

    for (int i = 0; i < n; ++i){
		printf("\n%d",ar[i]);
	}
	printf("\n");
	return 0;
}