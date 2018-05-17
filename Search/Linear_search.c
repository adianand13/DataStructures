//Program to implement linear search

//program using GNU GCC compiler
#include <stdio.h>
#include <stdlib.h>

//main function
int main(int argc, char const *argv[])
{
	system("clear");
	printf("Enter the size of the array\n");
	int n,i;
	scanf("%d",&n);
	int ar[n];
	printf("Eenter elements in the array\n");
	for(i = 0; i<n; ++i)
		scanf("%d",&ar[i]);
	printf("Enter the elements to be searched\n");
	int key;
	scanf("%d",&key);

	for(i = 0; i<n; i++){
		if (key==ar[i]){
			printf("%d is present at %d \n",key,i);
			break;
		}
	}	
	if(i==n)
		printf("%d Not Found in the Array\n",key);	
	return 0;
}
