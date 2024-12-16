/*
    Coded by Parth Pandya
    Problem Statement:- Creating a dynamic list with values ranging from 0 - 9, when the user wants to increment the last value of the 
                        list is incremented, if the value exceeds the value 9 ,the element is reset to 0 and its previous neighbouring 
                        element is incremented by one. If no neighbour is left a new member must be created will the value 1.
                          
          Eg:- List:- 7 8 8             |List:- 7 8 9             |List:- 9 9
               List:- 7 8 9 (increment) |List:- 7 9 0 (increment) |List:- 1 0 0 (increment)
*/
#include <stdio.h>// header files
#include <stdlib.h>

static int count1 = 0,count2 = 0;//global variables to keep count of the list

struct List1 //list 1 structure
{
    int data;
    struct List1* next;
}*first = NULL;

struct List2 //list 2 structure
{
    int data;
    struct List2* next;
}*front = NULL;

void addtolist1(struct List1** p,int value,int index)//function to add elements in list1
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
        
        if (*p == NULL)
        {
            *p = t;
        }
        
        else if (index == 1)
        {
            t->next = *p;
            *p = t;
        }
        
        else if (index == count1 + 1)
        {
            struct List1* curr = *p;
            
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            
            curr->next = t;
        }
        
        else
        {
            struct List1* curr1 = *p;
            struct List1* curr2;
            
            for (int i = 1;i<index;i++)
            {
                curr2 = curr1;
                curr1 = curr1->next;
            }
            
            t->next = curr1;
            curr2->next = t;
        }
        
        count1++;
    }
}

void addtolist2(struct List2** p,int value)// function to add elements in list2
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
        
        if (*p == NULL)
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
        
        count2++;
    }
}

void displaylist2(struct List2* p) //function to display list2
{
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void reverselist1(struct List1* p) //function to reverse list 1 and copy the value of element in list 2
{
    int A[count1];
    int i = 0,temp;
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    
    for (int i = 0;i<count1/2;i++)
    {
        temp = A[i];
        A[i] = A[count1 - i - 1];
        A[count1 - i - 1] = temp;
    }
    
    for (int i = 0;i<count1;i++)
    {
        addtolist2(&front,A[i]);
    }
}

void reverselist2(struct List2* p)// function to reverse list 2 and copy the elements in list1
{
    int A[count2];
    int i = 0,temp;
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    
    printf("Initial array is: ");
    for (int i = 0;i<count2;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
    for (int i = 0;i<count2/2;i++)
    {
        temp = A[i];
        A[i] = A[count2 - i - 1];
        A[count2 - i - 1] = temp;
    }
    
    int index;
    
    printf("Final array is: ");
    for (int i = 0;i<count2;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
    for (int i = 0;i<count2;i++)
    {
        index = count1 + 1;
        addtolist1(&first,A[i],index);
    }
}

void incrementlist(struct List2** p)//function to increment as per the problem statement
{
    struct List2* curr = *p;
    curr->data = curr->data + 1;
    int c = 0;
    while (c != 1)
    {
        if (curr->data == 10)
        {
            if (curr->next == NULL)
            {
                curr->data = 0;
                addtolist2(&front,1);
                c = 1;
            }
            
            else
            {
                curr->data = 0;
                curr->next->data = curr->next->data + 1;
                curr = curr->next;
                c = 0;
            }
        }
        
        else
        {
            c = 1;
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

void Freelist1(struct List1* p)// function to free the memory of list1
{
    while (p != NULL)
    {
        p = first->next;
        first->next = NULL;
        free(first);
        first = p;
    }
    count1 = 0;
}

void Freelist2(struct List2* p) //function to free the memory of list 2
{
    while (p != NULL)
    {
        p = front->next;
        front->next = NULL;
        free(front);
        front = p;
    }
    count2 = 0;
}

int main()
{
    int ch1,ch2,data,index,temp;
    
    do
    {
        printf("1) Add to list\n");//Menu
        printf("2) Display List\n");
        printf("3) Increment List\n");
        printf("4) Exit\n");
        scanf("%d",&ch1);
        
        switch (ch1)//logic
        {
            case 1:
            
                    if (count1 == 0)
                    {
                        printf("Enter the value of your element between (0 - 9)\n");
                        scanf("%d",&data);
                        
                        temp = count1 + 1;
                        addtolist1(&first,data,temp);
                    }
                    
                    else
                    {
                  printf("\n1)Add at the rear of your list\n");
                  printf("2)Insert at a particular index of the list\n");
                  scanf("%d",&ch2);
                  
                  switch (ch2)
                  {
                      case 1:
                            printf("Enter the value of the element between (0 - 9)\n");
                            scanf("%d",&data);
                            
                            temp = count1 + 1;
                            addtolist1(&first,data,temp);
                            break;
                            
                     case 2:
                            printf("Enter the index at which you want to insert an element (current index range of list 1 - %d)\n",count1);
                            scanf("%d",&index);
                            
                            printf("Enter the value of your element between (0 - 9)\n");
                            scanf("%d",&data);
                        
                            addtolist1(&first,data,index);
                            break;
                            
                    default:
                            printf("Invalid Input!\n");
                }  
            }
                    break;
            
            case 2:
                    if(count1 == 0)
                    {
                        printf("The list is empty\n");
                    }
                    
                    else
                    {
                        displaylist1(first);
                    }
                    break;
                    
            case 3: //This is written in details so the user will get a idea of how the increment is working
                    reverselist1(first);
                    printf("List 1 is: ");
                    displaylist1(first);
                    printf("\n");
                    printf("List 2 is: ");
                    displaylist2(front);
                    printf("\n");
                    Freelist1(first);
                    incrementlist(&front);
                     printf("List 2 is: ");
                    displaylist2(front);
                    printf("\n");
                    reverselist2(front);
                     printf("List 1 is: ");
                    displaylist1(first);
                    printf("\n");
                    Freelist2(front);
                    break;
                    
            case 4:
                    printf("You have exited the program...\n");
                    break;
                    
            default:
                    printf("Invalid Input!\n");
        }
    }while (ch1 != 4);
    
    return 0;
}// Thank You my friend