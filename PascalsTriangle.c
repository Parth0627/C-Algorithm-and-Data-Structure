 /*
   Coded by Parth Pandya
   Problem statement:- To print Pascal’s triangle taking user input.
   Eg:-  Input = 5
         Output:-     1
                     1 1
                    1 2 1
                   1 3 3 1
                  1 4 6 4 1
 */

#include <stdio.h>//header files
#include <stdlib.h>

struct List1 //i use linked lists to be updated as per the requirements
{
    int data;
    struct List1* next;
}*first = NULL;

struct List2
{
    int data;
    struct List2* next;
}*top = NULL;

void addtolist1(struct List1** p,int value)//function to add to list1
{
    struct List1* t;
    t = (struct List1*)malloc(sizeof(struct List1));
    
    if (t == NULL)
    {
        printf("Memory Overflow!\n");
    }
    
    else
    {
        t->data = value;
        t->next = NULL;
        if (*p == NULL)
        {
            *p = t;
        }
        else
        {
            struct List1* curr = *p;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
        }
    }
}

void addtolist2(struct List2** p,int value) //function to add  to list2
{
    struct List2* t;
    t = (struct List2*)malloc(sizeof(struct List2));
    
    if (t == NULL)
    {
        printf("Memory Overflow!\n");
    }
    
    else
    {
        t->data = value;
        t->next = NULL;
        if (top == NULL)
        {
            *p = t;
        }
        else
        {
            struct List2* curr = *p;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
        }
    }
}

void copyfromlist2(struct List2* q) //function to copy elements of list 2 to list1
{
    while(q != NULL)
    {
        addtolist1(&first,q->data);
        q = q->next;
    }
}

void updatelist2(struct List1* p) //function to update list 2 
{
    int temp;
    while (p->next != NULL)
    {
        temp = p->data + p->next->data;
        addtolist2(&top,temp);
        p = p->next;
    }
}

void Freelist1(struct List1*p) //function to free the memory from list 1
{
    while (p != NULL)
    {
        p = first->next;
        first->next = NULL;
        free(first);
        first = p;
    }
}

void Freelist2(struct List2*p) //function to free the memory from list 2
{
    while (p != NULL)
    {
        p = top->next;
        top->next = NULL;
        free(top);
        top = p;
    }
}

void displaylist2(struct List2* p) //function to display list 2
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int num;
    
    printf("Enter your number\n");
    scanf("%d",&num); //taking the number input from user
     
    addtolist2(&top,1);
    addtolist2(&top,1);//initializing list 2
    
    for (int i = 1;i<=num;i++) //logic
    {
       for (int j = 0;j<num+1 - i;j++)
        {
           printf(" ");
         }
        if (i == 1)
          {
              printf("1\n");
            }   
        else
          {
            displaylist2(top);
            Freelist1(first);
            copyfromlist2(top);
            Freelist2(top);
            addtolist2(&top,1);
            updatelist2(first);
            addtolist2(&top,1);
            }
    }
    return 0;
}// Thank you my friend
