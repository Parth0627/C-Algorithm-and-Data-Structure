/*
    Coded by Parth Pandya
    Problem Statement:- Creating a dynamic list with values ranging from 0 - 9, when the user wants to increment the last value of the 
                        list is incremented, if the value exceeds the value 9 ,the element is reset to 0 and its previous neighbouring 
                        element is incremented by one. If no neighbour is left a new member must be created will the value 1.(Amazon asked medium level)
                          
          Eg:- List:- 7 8 8             |List:- 7 8 9             |List:- 9 9                   
               List:- 7 8 9 (increment) |List:- 7 9 0 (increment) |List:- 1 0 0 (increment)
*/
#include <stdio.h>//header files
#include <stdlib.h>

static int count = 0;//global count variable

struct List//structure of list
{
    struct List* back;
    int data;
    struct List* next;
}*first = NULL,*last = NULL;

void addtolist(struct List** p,int value,int index)// function to add to list
{
    struct List* t;
    t = (struct List*)malloc(sizeof(struct List));
    
    if (t == NULL)
    {
        printf("Memory Overflow\n");
    }
    
    else
    {
        t->data = value;
        t->next = NULL;
        t->back = NULL;
        
        if (*p == NULL)
        {
            *p = t;
        }
        
        else if (index == 1)
        {
            t->next = *p;
            (*p)->back = t;
            *p = t;
        }
        
        else if (index == count + 1)
        {
            struct List* curr = *p;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            
            curr->next = t;
            t->back = curr;
        }
        
        else
        {
            struct List* curr1 = *p;
            struct List* curr2;
            
            for (int i = 1;i<index;i++)
            {
                curr2 = curr1;
                curr1 = curr1->next;
            }
            
            curr2->next = t;
            t->next = curr1;
            curr1->back = t;
            t->back = curr2;
        }
        
        struct List** q = &last;
        struct List* curr = *p;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        *q = curr;
        count++;
    }
}

void increment(struct List** p)// function to increment
{
    struct List* curr = *p;
    curr->data = curr->data + 1;
    int c = 0;
    
    while (c != 1)
    {
        if (curr->data == 10)
        {
            if (curr->back == NULL)
            {
                curr->data = 0;
                addtolist(&first,1,1);
                c = 1;
            }
            
            else
            {
                curr->data = 0;
                curr->back->data = curr->back->data + 1;
                curr = curr->back;
                c = 0;
            }
        }
        
        else
        {
            c = 1;
        }
    }
}

void displaylist(struct List* p)// function to display
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
    int ch1,ch2,data,index;
    
    do
    {
        printf("1) Add to list\n");// user menu
        printf("2) Display List\n");
        printf("3) Increment\n");
        printf("4) Exit\n");
        scanf("%d",&ch1);
        
        switch (ch1)// logic
        {
            case 1:
                    if (count == 0)
                    {
                        printf("Enter the value of the element\n");
                        scanf("%d",&data);
                        
                        index = 1;
                        addtolist(&first,data,index);
                    }
                    
                    else 
                    {
                        printf("\n1)Insert at the rear of the list\n");
                        printf("2) Insert at a specific index of the list\n");
                        scanf("%d",&ch2);
                        
                        switch (ch2)
                        {
                            case 1:
                                    printf("Enter the value of the element\n");
                                    scanf("%d",&data);
                                    
                                    index = count + 1;
                                    addtolist(&first,data,index);
                                    break;
                                    
                            case 2:
                                    printf("Enter the index at which you want to insert the element (current index range 1 - %d)\n",count);
                                    scanf("%d",&index);
                                    
                                    printf("Enter the value of the element\n");
                                    scanf("%d",&data);
                                    
                                    addtolist(&first,data,index);
                                    break;
                                    
                            default:
                                    printf("Invalid Input\n");
                        }
                    }
                            break;
                   
                    case 2:
                            displaylist(first);
                            break;
                            
                    case 3:
                            increment(&last);
                            printf("The incremented list is: ");
                            displaylist(first);
                            break;
                            
                    case 4:
                            printf("You have exited the program\n");
                            break;
                            
                    default:
                            printf("Invalid Input\n");
                    
               }
       }while (ch1 != 4);
    
    return 0;
}// Thank you my friend
