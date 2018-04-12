/*Write a program to create and traverse the elements of linked list*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	int info;
};

//function to display menu
void displayMenu();
//function to insert element
int insert();
//function to display linked list
void display();
//function to de-allocate memory
void de_allocate();

struct node *head=NULL;//stores head
struct node *top=NULL;//stores top of the list


int main(int argc, char const *argv[])
{
	int ch=0;
    do{
		displayMenu();
		scanf("%d",&ch);
        switch(ch){
            case 1:	if (insert()) printf("Element Inserted...!\n");
                    else printf("   <<<Insertion operation failed>>>\n");
                    break;
            case 2: if(head==NULL) printf("\n\t<<<Enter data first>>>");
            		else display();
                    break;
            case 3: printf("Exiting.......!\n");
                    de_allocate();
                    return 0;
            default:printf("\nInvalid input.....!");
        }
    }while(ch!=3);
	return 0;
}

void displayMenu(){
    printf("\n+----------------------------------------+\n");
    printf("|              <Linked List>             |\n");
    printf("+----------------------------------------+\n");
    printf("| 1.Add To list                          |\n");
    printf("| 2.display List                         |\n");
    printf("| 3.Exit.                                |\n");
    printf("+----------------------------------------+");

    printf("\n\nEnter your choice\t:\t");
}

int insert(){
    if(head==NULL){
    	head = (struct node *)malloc(1*sizeof(struct node));;
    	if(head==NULL) return 0;
    	else{
	    	printf("Enter new data\t\t:\t");
	        int data;
	        scanf("%d",&data);
	        head->info=data;
	        top=head;
	        head->next=NULL;
	        display();
	        return 1;
    	}
    }
    else{
    	struct node *temp =(struct node *)malloc(1*sizeof(struct node));
    		if (temp==NULL) return 0;
    	else{
    		top->next=temp;
    		top=temp;
    		printf("Enter new data\t\t:\t");
	        int data;
	        scanf("%d",&data);
	        top->info=data;
	        display();
	        return 1;
    	}    
    }
}

void display(){
	printf("List\t\t\t:\t");
	if (head==NULL) printf("<<<EMPTY>>>");
	else{
		struct node *temp=head;
        do{
        	printf("%d ",temp->info);
        	temp=temp->next;
        }while(temp!=NULL);
        printf("\n"); 
    }          
}

void de_allocate(){
	struct node *temp = head;
    while(head->next!=NULL){
        head=head->next;
        free(temp);
    }
}

