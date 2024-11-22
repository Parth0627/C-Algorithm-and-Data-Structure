/*
   Coded by - Parth Pandya
Problem statement:-
To find the Greatest Common Divisor(GCD) of list of number entered by the user which he/she can modify as per their convinience.
Follow all the rules of calculating GCD and i have used the logic , GCD (A,B,C) = GCD(GCD(A,B),C) = GCD(D,C) = some number.
*/

#include <stdio.h> //header files
#include <stdlib.h>

static int count = 0; // a static variable i took for extra use

struct Main //structure for the main list
{
    int data;
    struct Main* next;
}*first = NULL;

struct Factor //structre for the factor list
{
    int data;
    struct Factor* next;
}*front = NULL;

struct Duplicate //structre for the duplicate list
{
    int data;
    struct Duplicate* next;
}*top = NULL;

void addtomain(struct Main* p,int value) //function to add to main list
{
    struct Main* t;
    t = (struct Main*)malloc(sizeof(struct Main));
    
    if (t == NULL)
    {
        printf("Memory is Full\n");
    }
    else
    {
        t->data = value;
        t->next = NULL;
        
        if (first == NULL)
        {
            first = t;
            count++;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            if (p->data == 0 && value == 0)
            {
                printf("\nCannot and 2 zeros continuosly as GCD(0,0) is undefined\n");
            }
            else
            {
            p->next = t;
            count++;
            }
        }
    }
}

void deletefrommain(struct Main* p,int index) //function to delete from main list at desired index
{
    struct Main* q = NULL;
    if (index == 1)
    {
       first = first->next;
       free(p);
       count--;
    }
    else
    {
        for (int i = 0;i<index-1;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        p->next = NULL;
        free(p);
        count--;
    }
}
void addtofactor(struct Factor** p,int value) //function to add to factor list
{
    struct Factor* t;
    t = (struct Factor*)malloc(sizeof(struct Factor));
    
    if (t == NULL)
    {
        printf("Memory is Full\n");
    }
    else
    {
        t->data = value;
        t->next = NULL;
        struct Factor* curr = *p;
        if (*p == NULL)
        {
            *p = t;
        }
        else
        {
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
        }
    }
}

void addtoduplicate(struct Duplicate** p,int val) //fucntion to add to duplicate list
{
    struct Duplicate* t;
    t = (struct Duplicate*)malloc(sizeof(struct Duplicate));
    
    if (t == NULL)
    {
        printf("Memory is Full\n");
    }
    else
    {
        t->data = val;
        t->next = NULL;
        struct Duplicate* curr = *p;
        if (*p == NULL)
        {
            *p = t;
        }
        else
        {
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
        }
    }
}

void factorsof(int val1,int val2) //finding the factors and then adding them to the factor list
{
    int A[2] = {val1,val2};
    for (int i = 0;i<2;i++)
    {
        for (int j = 1;j<=A[i];j++)
        {
            if (A[i] % j == 0)
            {
                addtofactor(&front,j);
            }
        }
    }
}

void checkduplicate(struct Factor* curr,int value) //finding the duplicate values and adding them to the duplicate list
{
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            if (curr->data == value)
            {
                addtoduplicate(&top,value);
                break;
            }
            else
            {
                curr = curr->next;
            }
        }
        else
        {
            if (curr->next->data == value)
            {
                addtoduplicate(&top,value);
                break;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
}

void duplicate(struct Factor* p) //function to iterate through values of factor list to check wether they are duplicate
{
    int temp = 0;
    while(p->next != NULL)
    {
         temp = p->data;
        checkduplicate(p,temp);
        p = p->next;
    }
}

int maxof(struct Duplicate* p) //function to find the maximum value from the final duplicate list 
{
    int max = 0;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
            p = p->next;
        }
        else
        {
            p = p->next;
        }
    }
    return max;
}

void Freefactor(struct Factor** p) //function to free the memory of factor list after its required use
{
   struct Factor* curr = *p;
    while ( curr != NULL)
    {
        curr = (*p)->next;
        (*p)->next = NULL;
        free((*p));
        *p = curr;
    }
}

void FreeTop(struct Duplicate** p) //function to free the memory of duplicate list after its required use
{
    struct Duplicate* curr = *p;
    while ( curr != NULL)
    {
        curr = (*p)->next;
        (*p)->next = NULL;
        free((*p));
        *p = curr;
    }
}

void displaymain(struct Main* p) //function to display main list
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void displayfactor(struct Factor* p) //function to display factor list (i had used it to check if there are memory leaks at any point)
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
} 

void displayduplicate(struct Duplicate* p) //function to display the duplicate list (same use as displayfactor)
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
} 

void greatestcd(int value1,int value2) //finding gcd of 2 selected elements 
{
    factorsof(value1,value2);
    duplicate(front);
}

int gcdofall(struct Main* p) //finding gcd of whole list of the user
{
    int gcd;
    int temp = p->data;
    while (p->next != NULL)
    {
        if (temp == 0)
    {
        gcd = p->next->data;
        p = p->next;
    }
    else if (p->next->data == 0)
    {
        gcd = temp;
        p = p->next;
    }
    else
    {
        greatestcd(temp,p->next->data);
        gcd = maxof(top);;
        p = p->next;
        Freefactor(&front);
        FreeTop(&top);
     }
     temp = gcd;
   }
    return temp;
}

int main()
{
   
    int ch,data,index;
    do
    {
        printf("1) Add to list\n"); //user menu
        printf("2) Delete from the list\n");
        printf("3) Display main list\n");
        printf("4) The greatest common divisor of your current list\n");
        printf("5) Exit\n");
       while(scanf("%d",&ch) != 1)
       {
           printf("Invalid Input please enter a valid intger\n");
           while(getchar() != '\n');
       }
        
        switch (ch) //cases to be executed as per users use
        {
            case 1:
                    printf("Enter your element\n");
                    while(scanf("%d",&data) != 1)
                   {
                    printf("Invalid Input please enter a valid intger\n");
                    while(getchar() != '\n');
                    }
                    if (data < 0)
                    {
                        data = 0-data;
                        printf("\n\n-%d is coverted to %d as GCD is calculated of positive numbers\n\n",data,data);
                        addtomain(first,data);
                    }
                    else
                    {
                      addtomain(first,data);
                    }
                    printf("\n");
                    break;
                  
            case 2:
                    if (first == NULL)
                    {
                        printf("\n\nList is Empty\n\n");
                    }
                    else if (first->next == NULL)
                    {
                      deletefrommain(first,1);
                        printf("\n\nThe list is Empty Now\n\n");
                    }
                    else
                    {
                    printf("\nEnter the index of the element you want to delete (Index's of your current list from 1 to %d)\n",count);
                    while(scanf("%d",&index) != 1)
                    {
                        printf("Invalid Input please enter a valid intger\n");
                        while(getchar() != '\n');
                    }
                    if (index<1 || index>count)
                    {
                        printf("\nPlease Enter an index from 1 to %d\n",count);
                        while(scanf("%d",&index) != 1)
                        {
                            printf("Invalid Input please enter a valid intger\n");
                            while(getchar() != '\n');
                        }
                        deletefrommain(first,index);
                        printf("\n");
                    }
                    else
                    {
                        deletefrommain(first,index);
                        printf("\n");
                      }
                    }
                    break;
                    
            case 3:
                    if (first == NULL)
                    {
                        printf("\n\nThe list is empty\n\n");
                    }
                    else
                    {
                        printf("\nYour current list is: ");
                        displaymain(first);
                        printf("\n");
                    }
                    break;
                    
            case 4:
                    if (first == NULL)
                    {
                        printf("\n\nThe list is Empty\n\n");
                    }
                    else if (first->next == NULL)
                    {
                        printf("\n\nNeed minimum 2 elements to find the greatest common divisor\n\n");
                    }
                    else
                    {
                        printf("\n\nThe greatest common divisor of your current list is: %d\n\n",gcdofall(first));
                    }
                   break;
                   
            case 5:
                   printf("\n\nYou have exited the program\n\n");
                    break;
                    
            default:
                    printf("\n\nInvalid Input\n\n");
                    break;
                }
                
        } while(ch != 5);
        
    return 0;
} //THANK YOU MY FRIEND

