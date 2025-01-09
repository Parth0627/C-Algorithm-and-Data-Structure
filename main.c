/*
    Problem Statement:- You are given two non-empty linked lists representing two non-negative integers. The digits 
    are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the
    sum as a linked list.You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    
    Eg:- Input: list1 = [2,4,3], list2 = [5,6,4]    | Eg:- Input: list1 = [9,9,9,9,9,9,9], list2 = [9,9,9,9]
         Output: [7,0,8]                            |      Output: [8,9,9,9,0,0,0,1]
         Explanation: 342 + 465 = 807.              |      Explanation:- 9999999 + 9999 = 10009998.
*/

#include <stdio.h>//header files
#include <stdlib.h>

struct List1//structure for list 1
{
    int data;
    struct List1* next;
}*first = NULL;

struct List2//structure for list 2 
{
    int data;
    struct List2* next;
}*front = NULL;

struct Addlist// structure for the final sum list
{
    int data;
    struct Addlist* next;
}*top = NULL;

void addtolist1(struct List1* p,int value)//function to add to list 1
{
    struct List1* t;
    t = (struct List1*)malloc(sizeof(struct List1));
    
    if (t == NULL)
    {
        printf("Memory Overflow\n");
    }
    else
    {
        t->data = value;
        t->next = NULL;
        
        if(first == NULL)
        {
            first = t;
        }
        else
        {
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
        }
    }
}

void displaylist1(struct List1* p)// function to display list 1
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void addtolist2(struct List2* p,int value)// function to add to list 2
{
    struct List2* t;
    t = (struct List2*)malloc(sizeof(struct List2));
    
    if (t == NULL)
    {
        printf("Memory Overflow\n");
    }
    else
    {
        t->data = value;
        t->next = NULL;
        
        if(front == NULL)
        {
            front = t;
        }
        else
        {
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
        }
    }
}

void displaylist2(struct List2* p) // function to display list 2
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void addtoAddlist(struct Addlist** p,int value)// function to add to the final sum list
{
    struct Addlist* t;
    t = (struct Addlist*)malloc(sizeof(struct Addlist));
    
    if (t == NULL)
    {
        printf("Memory Overflow\n");
    }
    else
    {
        t->data = value;
        t->next = NULL;
        
        if(*p == NULL)
        {
            *p = t;
        }
        else
        {
            struct Addlist* curr = *p;
            
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
        }
    }
}

void displayAddlist(struct Addlist* p)// function to display the final sum list
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void adding(struct List1* p,struct List2* q)// main function which does the adding as per the required problem
{
    int temp,c = 0,carry = 0;
    while(c != 1)// logic
    {
        if(p != NULL && q != NULL)
        {
            temp = p->data + q->data + carry;
            if(temp >= 10)
            {
                temp = temp - 10;
                carry = 1;
                addtoAddlist(&top,temp);
            }
            else
            {
                addtoAddlist(&top,temp);
                carry = 0;
            }
            p = p->next;
            q = q->next;
        }
        else if(p != NULL && q == NULL)
        {
            temp = p->data + carry;
            if(temp >= 10)
            {
                temp = temp - 10;
                carry = 1;
                addtoAddlist(&top,temp);
            }
            else
            {
                addtoAddlist(&top,temp);
                carry = 0;
            }
            p = p->next;
        }
        else if(p == NULL && q != NULL)
        {
            temp = q->data + carry;
            if(temp >= 10)
            {
                temp = temp - 10;
                carry = 1;
                addtoAddlist(&top,temp);
            }
            else
            {
                addtoAddlist(&top,temp);
                carry = 0;
            }
            q = q->next;
        }
        else
        {
            c = 1;
        }
    }
    
    if(carry != 0)
    {
        addtoAddlist(&top,carry);
        carry = 0;
    }
}

int main()
{
    int ch1 = 0,ch2 = 0,data;
    // logic for user interface 
    do
    {
        printf("1) Add to list 1\n");
        printf("2) Done with list 1 now start adding in list 2\n");
        scanf("%d",&ch1);
        
        switch (ch1)
        {
            case 1:
                    printf("Enter the value of the element\n");
                    scanf("%d",&data);
                    
                    addtolist1(first,data);
                    break;
                    
            case 2:
                    printf("\n");
                    break;
                    
            default:
                    printf("Invalid Input\n");
        }
    }while (ch1 != 2);
    
    do
    {
        printf("1) Add to list 2\n");
        printf("2) Do the final adding (list 1 + list 2)\n");
        scanf("%d",&ch2);
        
        switch(ch2)
        {
            case 1:
                    printf("Enter the value of the element\n");
                    scanf("%d",&data);
                    addtolist2(front,data);
                    break;
                    
            case 2:
                    printf("\n");
                    printf("Your list 1 is: ");
                    displaylist1(first);
                    printf("Your list 2 is: ");
                    displaylist2(front);
                    
                    adding(first,front);
                    
                    printf("Adding both the list as per the required problem gives us: ");
                    displayAddlist(top);
                    break;
                    
            default:
                    printf("Invalid Input\n");
        }
        
    }while(ch2 != 2);
    
   return 0;
}//Thank You My Friend