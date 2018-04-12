
#include<stdio.h>
#include<stdlib.h>

//function to display menu
void displayMenu();
//function to perform insertion operation
int insert(int *que,int size);
//function to display elements in the stack
void display(int *que);

int front=0;//position of first element
int rear=0;//position of last element

int main(int argc, char const *argv[])
{
    system("clear");
    int ch=0,n;
    if (ch==0){
        printf("Enter the size of the Queue\n");
        scanf("%d",&n);
    }
    int queue[n];
    do{
        displayMenu();
        scanf("%d",&ch);
        switch(ch){
            case 1: if (insert(&queue[0],n)) printf("Element Inserted..!\n");
                    else printf("\n\t<<<Insertion operation failed>>>\n");
                    break;
            case 2: if(front==rear){ 
                        front=rear=0;
                        printf("No element in Queue to delete\n");
                    }
                    else{++front; display(&queue[0]);}
                    break;
            case 3: display(&queue[0]); 
                    break;
            case 4: front=rear=0; printf("Queue Reseted\n");
                    break;
            case 5: printf("Exiting.......!\n");
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

int insert(int *que,int size){
    if(rear==size){
        printf("\nQueue is full...!\n");
        display(que);
        return 0;
    }
    else{
        printf("Enter new data\t\t:\t");
        int data;
        scanf("%d",&data);
        rear++;
        *(que+rear)=data;
        display(que);
        return 1;
    }
}

void display(int *que){
    printf("Queue is\t\t:\t");
    if (rear==front) printf(" <<<EMPTY>>>");
    else
        for (int i = rear;i > front; --i)
            printf("%d ",*(que+i));
    printf("\n");    
}


    