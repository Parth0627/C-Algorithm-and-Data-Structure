/*
    Coded by Parth Pandya
    Problem Statement:- Infix to postfix conversion operators included(+,-,*,/,(,),%)
    Eg:- Input:- ((P+Q)*(R-S))/((T+U)*(V-W))            (an infix expression)
         Output:- PQ+RS-*TU+VW-*/                       //(an postfix expression) 

#include <stdio.h>// header files
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack// structure for stack
{
    struct Stack* back;
    char data;
    struct Stack* next;
}*top = NULL;

void addtostack(struct Stack** p,char value)// funtion to push in stack
{
    struct Stack* t;
    t = (struct Stack*)malloc(sizeof(struct Stack));
    
    if (t == NULL)
    {
        printf("Memory Overflow\n");
    }
    
    else
    {
        t->back = NULL;
        t->data = value;
        t->next = NULL;
        
        if (*p == NULL)
        {
            *p = t;
        }
        
        else
        {
           (*p)->next = t;
           t->back = *p;
            *p = t;
        }
    }
}

char pop(struct Stack** p)// function to pop from stack
{
    char temp;
    
        struct Stack* curr = *p;
        temp = curr->data;
        
        if (curr->back == NULL)
        {
            *p = NULL;
        }
        else
        {
        *p = (*p)->back;
        (*p)->next = NULL;
        }
        free(curr);
    
    return temp;
}

void displaystack(struct Stack* p)// function to display stack , though its not used in program i used it to check the stack
{
    while (p != NULL)
    {
        printf("%c\n",p->data);
        p = p->back;
    }
}

bool isOperand(char s)// function to check if is a operand
{
    if(s == '+' || s == '-' || s == '*' || s == '/' || s == '%' || s == '(' || s == ')')
    {
        return false;
    }
    return true;
}

bool isParanthesis(char s)// function to check if the paranthesis is ending
{
    if (s == ')')
    {
        return true;
    }
    return false;
}

char stacktop(struct Stack* p)// function to give stack top
{
    char temp = p->data;
        return temp;
}

bool isEmpty(struct Stack* p)//function to check if the stack is empty
{
    if(p == NULL)
    {
        return true;
    }
    return false;
}

bool isLower(char s)// function to check if the operator and the stacktop has lower precedence or not
{
    if(isEmpty(top))
    {
        return false;
    }
    else
    {
        char temp = stacktop(top);
        if (s == '+' || s == '-')
        {
            if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '%')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(s == '*' || s == '/' || s =='%')
        {
            if(temp == '*' || temp == '/' || temp == '%')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(s == '(')
        {
            return false;
        }
    }
    return false;
}

void infixtopostfix(char s1[100], char* s2)// the function that has the main logic for conversion
{
    int k = 0,c = 0,d = 0,e = 0;
    char gar;
    
    for (int i = 0;i<strlen(s1);i++)// logic
    {
    if(isOperand(s1[i]))
    {
        s2[k] = s1[i];
        k++;
    }
    else
    {
        if(isParanthesis(s1[i]))
        {
            while(c != 1)
            {
                gar = pop(&top);
                
                if(gar == '(')
                {
                    c = 1;
                }
                else
                {
                s2[k] = gar;
                k++;
                c = 0;
                }
            }
            c = 0;
        }
        
        else
        {
            if(isLower(s1[i]))
            {
                while(d != 1)
                {
                    gar = pop(&top);
                    s2[k] = gar;
                    k++;
                    
                    if(isLower(s1[i]))
                    {
                        d = 0;
                    }
                    else
                    {
                        addtostack(&top,s1[i]);
                        d = 1;
                    }
                }
                d = 0;
            }
            else
            {
                addtostack(&top,s1[i]);
            }
        }
      }
    }
    
    if(!isEmpty(top))
    {
        while (e != 1)
        {
            gar = pop(&top);
            s2[k] = gar;
            k++;
            
            if(isEmpty(top))
            {
                e = 1;
            }
            else
            {
                e = 0;
            }
        }
    }
    
    printf("%s\n",s2);// printing the postfix expression
}

int main()
{
    char s1[100],s2[100];
    printf("Enter your INFIX expression\n");// input a valid infix expression
    fgets(s1,sizeof(s1),stdin);
    
    s1[strlen(s1) - 1] = '\0';// removing the newline character added by the fgets
    infixtopostfix(s1,s2);
    
    return 0;
}// Thank you my friend
