/*Write a program to evaluate postfix expression using Stack.*/

/*
  evalutes a postfix expression based on predefined standard rules
  enterd expression should be in the given format.
  Operands can be contigous string of numbers, while each unique operand must be separated by a delimiter
  operator must be single character.
  Only '+'  ,  '-'  , '*', '/' and '^' (for exponentiation) operators are valid.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//function to push value into the stack
void push_stack(int num);

//function to evalute the postfix expression
int postfix_evaluation();

//performs the pop operation on the stack
int pop();

int top=-1;           //flag for top of the stack
char expression[50]; //stores the input from the user
int stack[50];      //stack of an array    

int main()
{
    system("clear");
    printf("\nEnter a postfix expression\n[ Separate each number by underscore ]\n\n");
    scanf("%s",expression);
    printf("\nEvaluating expression......!\n");
    printf("\nOn evaluating\t:\t%d\n",postfix_evaluation());
}

int postfix_evaluation()
{
    for (int i = 0; expression[i]!='\0'; i++)
    {
        //skip the entire itterarion if seprator is found
        //reduces the time complexity
        if(expression[i] == '_' || expression[i] == ',' || expression[i]==' ') continue;
        
        int num=0,num1,num2;
        if (expression[i] >= 48 && expression[i] <=58)
         {
            while(expression[i] >= 48 && expression[i] <=58)//extracts the digit
            {
                num=num*10;
                switch(expression[i])
                {
                    case '0': num+=0;  
                        break;
                    case '1': num+=1;
                        break;
                    case '2': num+=2;
                        break;
                    case '3': num+=3;
                        break;
                    case '4': num+=4;
                        break;
                    case '5': num+=5;
                        break;
                    case '6': num+=6;
                        break;
                    case '7': num+=7;
                        break;
                    case '8': num+=8;
                        break;
                    case '9': num+=9;
                        break;
                }
                i++;
            }
            push_stack(num);
        } 
        switch(expression[i])
        {
            case '+':   num1 = pop();
                        num2 = pop();
                        num = num2 + num1;
                        printf("%d + %d = %d\n",num2,num1,num);
                        push_stack(num);
                break;
            case '-':   num1 = pop();
                        num2 = pop();
                        num = num2 - num1;
                        printf("%d - %d = %d\n",num2,num1,num);
                        push_stack(num);
                break;
            case '*':   num1 = pop();
                        num2 = pop();
                        num = num2 * num1;
                        printf("%d * %d = %d\n",num2,num1,num);
                        push_stack(num);
                break;
            case '/':   num1 = pop();
                        num2 = pop();
                        num = num2 / num1;
                        printf("%d / %d = %d\n",num2,num1,num);
                        push_stack(num);
                break;
            case '%':   num1 = pop();
                        num2 = pop();
                        num = num2 % num1;
                        printf("%d \\ %d = %d\n",num2,num1,num);
                        push_stack(num);
                break;
            case '^': num = pow(num1, num2);
                      printf("%d ^ %d = %d\n",num1,num2,num);
                      push_stack(num);
                break;
        }
    }
    if (top==0)
    {
        return pop();
    }
    else{
        printf("\nevaluation error!\ncheck your expression!");
        return pop();
    }     
}

void push_stack(int num)
{
    top++;
    stack[top]=num;
}
int pop()
{
        top--;
        return stack[top+1];
}