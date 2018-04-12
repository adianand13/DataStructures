/*Write a program to create a linked list and implement following operations on the list:
	-Insert a node at beginning
	-Insert a node at end of list
	-Delete a particular node.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};

//function to display menu
void displayMenu();
//function to insert element
int insert();
//function to insert element at begining
int insertBeggining();
//function to delete a particular node
void delete();
//function to display linked list
void display();
//function to de-allocate memory
void de_allocate();

struct node *head=NULL;//stores head
struct node *top=NULL;//stores top of the list

int main(int argc, char const *argv[])
{
	system("clear");
	int ch=0;
    do{
		displayMenu();
		scanf("%d",&ch);
        switch(ch){
            case 1:	if (insert()) printf("Element Inserted....!\n");
                    else 
                    	printf("   <<<Insertion operation failed>>>\n");
                    break;
            case 2:	if (insertBeggining()) printf("Element Inserted....!\n");
                    else 
                    	printf("   <<<Insertion operation failed>>>\n");
            case 3: break;
            case 4: if(head==NULL) printf("\n\t<<<Enter data first>>>");
            		else display();
                    break;
            case 5: printf("Exiting.......!\n");
                    de_allocate();
                    return 0;
            default:printf("\nInvalid input.....!");
        }
    }while(ch!=6);
	return 0;
}

void displayMenu(){
    printf("\n+----------------------------------------+\n");
    printf("|              <Linked List>             |\n");
    printf("+----------------------------------------+\n");
    printf("| 1.Add To list.                         |\n");
    printf("| 2.Insert at beginning.                 |\n");
    printf("| 3.delete a particular node.            |\n");
    printf("| 4.display List.                        |\n");
    printf("| 5.Exit.                                |\n");
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

int insertBeggining(){
	if (head==NULL)
		return insert();
	else{
		struct node *temp =(struct node *)malloc(1*sizeof(struct node));
		if (temp==NULL) return 0;
		else{
			temp = head;
			printf("Enter new data\t\t:\t");
		    int data;
		    scanf("%d",&data);
		    head->info=data;
		    head->next=temp;
		    display();
		    return 1;
		}
    }
}

void delete(){
	if (head==NULL)
	{
		printf("\t<<<List is Empty>>>\n");
		return;
	}
    printf("+----------------------------------------+\n");
    printf("| 1.Delete by value                      |\n");
    printf("| 2.Delete by position                   |\n");
    printf("+----------------------------------------+");
    printf("\n\nEnter your choice\t:\t");
    int ch;
    scanf("%d",&ch);
    struct node *temp = head;
    switch(ch){
    	case 1: printf("\nEnter the value\t:\t");
				int key;
				scanf("%d",&key);
				if(head->info==key){
					temp=head;
					head=head->next;
					free(temp);
				}
				else{
					struct node *temp2;
					while(temp!=NULL){
						temp2=temp->next;
		    			if (temp2->info==key)
		    				break;
		    			temp=temp->next;
					}
					if(temp==NULL)
						printf("value not found...!\n");
					else{
						temp->next=temp2->next;
						free(temp2);
						printf("Value Deleted : %d\n",key);
					}
				} 
			break;
		case 2:	printf("\nEnter the value\t:\t");
				int position;
				scanf("%d",&position);
				for (int i = 0; i < position; ++i, temp=temp->next)
					if(temp==NULL){
						printf("\t<<<position out of bound>>>\n");
						break;
					}
				if (temp!=NULL){
					printf("Value Deleted : %d\n",temp->info);
					free(temp);
				}
			break;
		default : printf("Invalid input....!\n");

    }
    display();
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

