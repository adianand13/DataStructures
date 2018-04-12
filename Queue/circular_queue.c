/*WAP for implementing Insertion and deletion operations in Circular Queue*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	int info;
};
//function to display menu
void displayMenu();
//function to perform insertion operation
int insert();
//function to display elements in the stack
void display();
//function to de-allocated memory
void de_allocated();

struct node *front=NULL;//pointer to first element
struct node *rear=NULL;//pointer to last element
int count=0;//keeps count  of total elements
int size;  //stores the size of the queue

int main(int argc, char const *argv[])
{
	system("clear");
	int ch=0;
	do{
		if(ch==0){ //when queue is not established
			printf("Enter the size of the Queue\n");
			scanf("%d",&size);
			for (int i = 0; i < size; ++i){//loop to create circular queue
				if(i==0){
					front=(struct node *)malloc(1*sizeof(struct node));
					rear=front;
					continue;
				}
				struct node *temp =(struct node *)malloc(1*sizeof(struct node));
				rear->next=temp;
				rear=temp;
			}
			rear->next=front;
            rear=front;
		}
		displayMenu();
		scanf("%d",&ch);
        switch(ch){
            case 1: if (insert()) printf("Element Inserted...!\n");
                    else printf("   <<<Insertion operation failed>>>\n");
                    break;
            case 2: if(count==0)printf("     <<<No element to delete>>>\n");
                    else{front=front->next; count--; display();}
                    break;
            case 3: display(); 
                    break;
            case 4: ch=0; printf("Queue Reseted\n");
                    de_allocated();
                    return 0;
                    break;
            case 5: printf("Exiting.......!\n");
                    de_allocated();
                    return 0;
            default:printf("\nInvalid input.....!");
        }
    }while(ch!=5);
	return 0;
}

void displayMenu(){
    printf("\n+----------------------------------------+\n");
    printf("|           <Queue Operations>           |\n");
    printf("+----------------------------------------+\n");
    printf("| 1.Insert New element                   |\n");
    printf("| 2.Delete an element                    |\n");
    printf("| 3.display Queue                        |\n");
    printf("| 4.Reset Queue                          |\n");
    printf("| 5.Exit                                 |\n");
    printf("+----------------------------------------+");

    printf("\n\nEnter your choice\t:\t");
}

int insert(){
    if(count==size){
        printf("\t<<<Queue is full>>>\n");
        display();
        return 0;
    }
    else{
        printf("Enter new data\t\t:\t");
        int data;
        scanf("%d",&data);
        rear->info=data;
        count++;
        display();
        rear=rear->next;
        return 1;
    }
}

void display(){
	printf("Queue is\t\t:\t");
	if (count==0) printf("<<<EMPTY>>>");
	else{
		struct node *temp=front;
        for (int i = 1; i <=count; ++i){
            printf("%d ",temp->info);
            temp=temp->next;
        }
	}
    printf("\n");           
}
void de_allocated(){
    for (int i = 0; i < size; ++i){
        struct node *temp = front;
        front=front->next;
        free(temp);
    }
}