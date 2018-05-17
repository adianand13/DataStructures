/*Write a Program to implement insertion Sort using array.*/

#include <stdio.h>
#include <stdlib.h>

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

	printf("\nGiven Array is");
	for (int i = 0; i < n; ++i)
		printf("\n%d",ar[i]);

	printf("\nSorting Array...!");
	for (int key, j, i = 0; i < n-1; i++)
	{
		key = ar[i];
       	for (j = i-1; j >= 0 && ar[j] > key ; j--)
       		ar[j+1] = ar[j];
        ar[j+1] = key;
	}

	printf("\nSorted Array is");
    for (int i = 0; i < n; ++i){
		printf("\n%d",ar[i]);
	}
	printf("\n");
	return 0;
}