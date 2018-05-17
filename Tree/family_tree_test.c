#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    int data;
    struct node* male;
    struct node* female;
    struct node* offspring;
};

int i=0;

//function to create new family member
struct node* newNode(char name[]);

//function to post post order
void printPostorder(struct node* node);

//function to print inorder
void printInorder(struct node* node);

//function to print pre order
void printPreorder(struct node* node);

//root node
struct node *root;

//function to display menu
void displayMenu();

//function to enter data in tree
void construct();

int main(int argc, char const *argv[])
{
    system("clear");
    printf("\nWelcome To family tree app\n");
    int ch;
    construct();
    do{
        displayMenu();
        printf()
        switch(ch){
            case 1:
                printf("\nPreorder traversal of binary tree is \n");
                printPreorder(root);
                break;
            case 2:
                printf("\nInorder traversal of binary tree is \n");
                printInorder(root);
            case 3:
                printf("\nPostorder traversal of binary tree is \n");
                printPostorder(root);
                break;
            case 4: return 0;
            default:printf("\nInvalid input.....!");
        }
    }while(1);
        
    return 0;
}

void displayMenu(){
    printf("\n+----------------------------------------+\n");
    printf("|              <Family Tree>             |\n");
    printf("+----------------------------------------+\n");
    printf("| 1.Pre-Order                            |\n");
    printf("| 2.In-Order                             |\n");
    printf("| 3.Post-Order                           |\n");
    printf("| 4.exit.                                |\n");
    printf("+----------------------------------------+");
}

struct node* newNode(char ar[])
{
    struct node* member = (struct node*)malloc(sizeof(struct node));
    strcpy(member->name,ar);
    // member->name=ar;
    member->data=i;
    i++;
    member->male = NULL;
    member->female = NULL;
    return(member);
}

void construct()
{
    char name[20];
    
    printf("\nFirst Genration :");
    printf("\nEnter your Name : ");
    scanf("%s",name);
    root=newNode(name);
    root->offspring=NULL;
    
    printf("\nSecond Genration :");
    printf("\nEnter your Father's Name : ");
    scanf("%s",name);
    root->male=newNode(name);
    root->male->offspring=root;
    
    printf("\nEnter your Mother's Name : ");
    scanf("%s",name);
    root->female=newNode(name);
    root->female->offspring=root;
    
    printf("\nThird Genration :");
    printf("\nEnter your GrandFather's Name : ");
    scanf("%s",name);
    root->male->male=newNode(name);
    root->male->male->offspring=root->male;
    
    printf("\nEnter your GrandMother's Name : ");
    scanf("%s",name);
    root->male->female=newNode(name);
    root->male->female->offspring=root->male;
    //Meternal
    printf("\nEnter your Maternal GrandFather's Name : ");
    scanf("%s",name);
    root->female->male=newNode(name);
    root->female->male->offspring=root->female;
    
    printf("\nEnter your Maternal GrandMother's Name : ");
    scanf("%s",name);
    root->female->female=newNode(name);
    root->female->female->offspring=root->female;
    
    printf("\nFourth Genration :");
    printf("\nEnter your Great-GrandFather's Name : ");
    scanf("%s",name);
    root->male->male->male=newNode(name);
    root->male->male->male->offspring=root->male->male;
    
    printf("\nEnter your Great-GrandMother's Name : ");
    scanf("%s",name);
    root->male->male->female=newNode(name);
    root->male->male->female->offspring=root->male->male;
    //GrandMother's
    printf("\nEnter your GrandMother's Father's Name : ");
    scanf("%s",name);
    root->male->female->male=newNode(name);
    root->male->female->male->offspring=root->male->female;
    
    printf("\nEnter your GrandMother's Mothers's Name : ");
    scanf("%s",name);
    root->male->female->female=newNode(name);
    root->male->female->female->offspring=root->male->female;
    //Maternal Great
    printf("\nEnter your Maternal Great-GrandFather's Name : ");
    scanf("%s",name);
    root->female->male->male=newNode(name);
    root->female->male->male->offspring=root->female->male;
    
    printf("\nEnter your Maternal Great-GrandMother's Name : ");
    scanf("%s",name);
    root->female->male->female=newNode(name);
    root->female->male->female->offspring=root->female->male;
    //Maternal GrandMother's
    printf("\nEnter your Maternal GrandMother's Father's Name : ");
    scanf("%s",name);
    root->female->female->male=newNode(name);
    root->female->female->male->offspring=root->female->female;
    
    printf("\nEnter your Maternal GrandMother's Mothers's Name : ");
    scanf("%s",name);
    root->female->female->female=newNode(name);
    root->female->female->female->offspring=root->female->female;
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    
    // first recur on left subtree
    printPostorder(node->male);
    
    // then recur on right subtree
    printPostorder(node->female);
    
    // now deal with the node
    printf("\n%d\t%s ", node->data,node->name);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    
    /* first recur on left child */
    printInorder(node->male);
    
    /* then print the data of node */
    printf("\n%d\t%s ", node->data,node->name);
    
    /* now recur on right child */
    printInorder(node->female);
}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    
    /* first print data of node */
    printf("\n%d\t%s ", node->data,node->name);
    
    /* then recur on left sutree */
    printPreorder(node->male);
    
    /* now recur on right subtree */
    printPreorder(node->female);
}
