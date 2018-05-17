/*Write a Program to implement merge Sort using array.*/

#include <stdio.h>
#include <stdlib.h>

/*function to merge two sorted arrays*/
void merge(int ar[], int l, int m, int r);
/*function to perform merg sort*/
void mergeSort(int ar[], int l, int r);

int main(int argc, char const *argv[])
{
	system("clear");
	int n, lower, upper;
	printf("\nEnter aray size : ");
	scanf("%d",&n);
	int ar[n];
	int ar_size = sizeof(ar)/sizeof(ar[0]);
	printf("\nEnter lower bound : ");
	scanf("%d",&lower);
	printf("\nEnter upper bound : ");
	scanf("%d",&upper);

	for (int i = 0; i < n; ++i)
		ar[i]=rand()%(upper-lower+1)+lower;

	printf("\nGiven Array is");
	for (int i = 0; i < n; ++i)
		printf("\n%d",ar[i]);

	 mergeSort(ar, 0, ar_size - 1);
	printf("\nSorted Array is");
	for (int i = 0; i < n; ++i)
		printf("\n%d",ar[i]);
}

void merge(int ar[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arays */
    int L[n1], R[n2];
 
    /* Copy data to temp arays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = ar[l + i];
    for (j = 0; j < n2; j++)
        R[j] = ar[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        ar[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        ar[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int ar[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(ar, l, m);
        mergeSort(ar, m+1, r);
 
        merge(ar, l, m, r);
    }
}
