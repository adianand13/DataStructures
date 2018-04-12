/*Write a program for implementation of stack using Linear Linked List.*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node
{
    int info;
    struct node *next;
    struct node *prvs;
};

//function to display menu
void displayMenu();

//function to push data into the stack
int push();

//function to pop element from the stac
void pop();

struct node *top=NULL;//keep tracks of the top of the node
unsigned int count=0;//to keep track of total number of elements
	
int main(){
	system("clear");
	int ch;
    do{
        displayMenu();
        scanf("%d",&ch);
        switch(ch){
            case 1:	if (push())	printf("\nElement Inserted..!\n");
            		else printf("\n<<<Push operation failed>>>\n");
            		break;
            case 2:	pop();
            		break;
            case 3:	while(top->prvs==NULL){
            			struct node *temp = top;
            			top=top->prvs;
            			free(temp);
            		}
            		free(top);
            		printf("\nStack deleted\n");
            		printf("Exiting.......!\n");
            		return 0;
            default: printf("\nInvalid input.....!");
        }
    }while(ch!=3);
    return 0;
}

void displayMenu(){
	printf("\n+----------------------------------------+\n");
	printf("|            <Stack Operations>          |\n");
	printf("+----------------------------------------+\n");
	printf("| 1.Insert New element                   |\n");
	printf("| 2.Pop an element                       |\n");
	printf("| 3.Exit                                 |\n");
	printf("+----------------------------------------+");

    printf("\n\nEnter your choice\t:\t");
}

int push(){
	printf("Enter new data\n");
	int data;
	scanf("%d",&data);
	//when stack is empty
	if(top==NULL){
		top=(struct node *)malloc(1*sizeof(struct node));
		top->prvs=NULL;
		top->next=NULL;//when empty, can't travel backward
		top->info=data;
	}
	else
    {
        struct node *temp;
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->prvs=top; //sets previous top element
        top = temp;	   //setting top to the new element
        temp=NULL; 
        top->info = data;
        top->next=NULL;
    }
    if(top==NULL) return 0;
    else {count++; return 1;}
    count++;
}

void pop()
{
	//when there is no element in the stack
	if (top==NULL) printf("stack empty...!\nEnter an elements First.\n");
	//when there is only one element in the stack
	else if(count==1){
        printf("\nPoped element\t:\t%d\n",top->info);
        free(top);
        top=NULL;
	} 
	else{
        struct node *temp=top->prvs;
        temp->next=NULL;
        free(top);
        top=temp;
        temp=NULL;
        printf("\nPoped element\t:\t%d\n",top->info);
    }
	count--;
}

