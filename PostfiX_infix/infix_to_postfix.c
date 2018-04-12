/*
  Infix to postfix conversion in C
  Input Postfix expression must be in a pre-defined format.
  operator must be single character.
  Only '+'  ,  '-'  , '*', '/' and '^' (for exponentiation)  operators are expected.
  use underscore or ',' as a delimiter
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
 
// Function to convert Infix expression to postfix
void InfixToPostfix(char expression[]);
 
// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);
 
// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);
 
// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

//functtion to push value into the stack
void push_stack(char num);

//function to pop value out of stack
int pop();

char stack[50];     //stack to store element in the stack
int top=-1;         //to store top of the stack
char postfix[50]; 
int top_post=-1;

int main(int argc, char const *argv[])
{
    system("clear");
    char expression[50];
    printf("Enter Infix Expression\n[ <do not use space> use underscore as delimiter ]\n");
    scanf("%s",expression);
    InfixToPostfix(expression);
    printf("Output = %s\n",postfix);
}
 
// Function to evaluate Postfix expression and return output
void InfixToPostfix(char expression[])
{
    // Declaring a Stack<array> to store the value
    
    
    for(int i = 0;i< strlen(expression);i++)
    {
        // Scanning each character from left.
        // If character is a delimiter, skip the current itteration.
        if(expression[i] == '_' || expression[i] == ',') continue;
 
        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(expression[i]))
        {
            while(top!=-1 && stack[top] != '(' && HasHigherPrecedence(stack[top],expression[i]))
            {
                top_post++;
                postfix[top_post]=stack[top];
                pop();
            }
            push_stack(expression[i]);
        }
        // Else if character is an operand
        else if(IsOperand(expression[i]))
        {
            top_post++;
            postfix[top_post]=expression[i];
        }
 
        else if (expression[i] == '(')
        {
            push_stack(expression[i]);
        }
 
        else if(expression[i] == ')')
        {
            while(top!=-1 && stack[top] != '(')
            {
                top_post++;
                postfix[top_post]=stack[top];
                pop();
            }
            pop();
        }
    }
 
    while(top!=-1)
    {
        top_post++;
        postfix[top_post]=stack[top];
        pop();
    } 
    // return postfix;
}

 
// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}
 
// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
        return true;
 
    return false;
}
 
// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
    if(op == '^') return true;
    return false;
}
 
// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
    {
    case '+':
    case '-':
        weight = 1;
    case '*':
    case '/':
        weight = 2;
    case '^':
        weight = 3;
    }
    return weight;
}

void push_stack(char num)
{
    top++;
    stack[top]=num;
}

int pop()
{
        top--;
        return stack[top+1];
}
// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
 
    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight)
    {
        if(IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ?  true: false;
}
 