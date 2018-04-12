/*Write a program to implement PUSH and POP operation in Stack using array.*/

#include<stdio.h>
#include<stdlib.h>

void menu();
int push(int* ar);
int pop(int* ar);
void display(int* ar);
int top=-1;
int max;

int main()
{
    system("clear");
    int p,ch=0,n;
    if(ch==0)
    {
        printf("Enter the size of the Stack\t:\t");
        scanf("%d",&n);
        max=n;
        ch=-1;
    } 
    int stack[n]; 
    do
    {
        menu();
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(push(&stack[0])){
                printf("Success\n");
                display(&stack[0]);
            }
            else
                printf("\n<<<<<Push operation failed>>>>>|\n");
            break;

            case 2:
            p=pop(&stack[0]);
            if(p==top)
                printf("Stack Empty");
            else
                printf("Poped element is %d",p);
                display(&stack[0]);
            break;

            case 3:
                printf("Exiting.......!\n");
                break;

            default: printf("\nInvalid input.....!");
            break;
        }
    }while(ch!=3);
}

//function to display menu
void menu()
{
    printf("\n1. Push operation\n2. Press pop operation\n3. Exit\n");
    printf("\n\nEnter your choice\t:\t");
}

//function to implement push operation
int push(int* ar)
{
    if(top==max){
        printf("Overflow");
        return 0;
    }
    else{
        printf("\nEnter The element to be inserted\t");
        int temp;
        scanf("%d",&temp);
        top++;
        *(ar+top)=temp;
        return 1; 
    }
    
}

//function to implement pop operation
int pop(int* ar)
{
    if(top==-1)
        return(top);
    else
    {
        top=top-1;
        return *(ar+top);
    }
}

//function to display the stack
void display(int* ar)
{
    int i;
    printf("\nStack is:\t");
    for(i=0;i<=top;i++)
        printf("%d\t",*(ar+i));
}