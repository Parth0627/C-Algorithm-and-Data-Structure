/* 
 Coded by Parth Pandya
  Problem statement:-  This is a chor and police game where 1 represents the police , 2 represents the wall and 0 represents the place
  where the chor can hide. The police can see in all 4 directions up, down, left,right but it cant see through the wall . So i have taken
  a 4x4 matrix ground to play(can do more number just will have to make changes in the loop limit accordingly) and this program helps to 
  find the number or places the chor can hide.
  Example :- 1 2 0 0 
             0 1 1 0  so in this matrix as per our game rules the chor hide in 4 places (0,3);(2,3);(3,2);(3,3)
             0 0 2 0  like this you can test further cases
             2 0 0 0
 */ 

#include <stdio.h> //header files
#include <stdlib.h>
#include <stdbool.h>

static int na = 0;

struct Nonaccesible //nonaccesible elements linked list
{
    int indexi;
    int indexj;
    struct Nonaccesible* next;
}*first = NULL;

void accept(struct Nonaccesible** p, int x, int y) //function to accept the non-accesible elements in its list
{
    struct Nonaccesible* t = (struct Nonaccesible*)malloc(sizeof(struct Nonaccesible));
    
    if (t == NULL)
    {
        printf("Memory Overflow\n");
    }
    else
    {
        t->indexi = x;
        t->indexj = y;
        t->next = NULL;
        struct Nonaccesible* curr = *p;
        
        if (*p == NULL)
        {
            *p = t;
            na++;
        }
        else
        {
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
            na++;
        }
    }
}

bool isPresent(struct Nonaccesible* p, int x, int y) //function to check if the elements is already there in the list to avoid duplication
{
    while (p != NULL)
    {
        if (p->indexi == x && p->indexj == y)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void display(struct Nonaccesible* p) //function to display the list of non accesible elements index in the array
{
    while (p != NULL)
    {
        printf("(%d,%d) ", p->indexi, p->indexj);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int A[4][4] = { //you can edit this but remember to change other things too accordingly eg if you do 4x6 then make the required changes
        { 1, 0, 0, 2},
        { 0, 1, 1, 0},
        { 0, 0, 2, 1},
        { 2, 0, 0, 0}
    };
    
    for (int i = 0; i < 4; i++) //my full logic 
    {
        for (int j = 0; j < 4; j++)
        {
            if (isPresent(first, i, j) && A[i][j] != 1)
            {
                continue;
            }
            else
            {
                if (A[i][j] == 2)
                {
                    accept(&first, i, j);
                    continue;
                }
                if (A[i][j] == 1)
                {
                    if (!isPresent(first,i,j))
                    {
                    accept(&first, i, j);
                    }
                    
                    for (int k = i + 1; k < 4; k++)
                    {
                        if (A[k][j] == 2)
                        {
                            break;
                        }
                        
                        if (isPresent(first, k, j))
                        {
                            continue;
                        }
                        
                        else
                        {
                            accept(&first, k, j);
                        }
                    }
                    
                    for (int l = j + 1; l < 4; l++)
                    {
                        if (A[i][l] == 2)
                        {
                            break;
                        }
                        
                        if (isPresent(first, i, l))
                        {
                            continue;
                        }
                        
                        else
                        {
                            accept(&first, i, l);
                        }
                    }
                    
                    for (int m = i - 1; m >-1; m--)
                    {
                        if (A[m][j] == 2)
                        {
                            break;
                        }
                        
                        if (isPresent(first, m, j))
                        {
                            continue;
                        }
                        
                        else
                        {
                            accept(&first, m, j);
                        }
                    }
                    
                    for (int n = j - 1; n > -1; n--)
                    {
                        if (A[i][n] == 2)
                        {
                            break;
                        }
                        
                        if (isPresent(first, i, n))
                        {
                            continue;
                        }
                        
                        else
                        {
                            accept(&first, i, n);
                        }
                    }
                }
            }
        }
    }
    
    display(first);
    printf("There are %d spaces in the matrix for the chor to hide\n",16-na);
    return 0;
}//Thank you my friend
