/*
    Coded by Parth Pandya
    Problem Statement:- Printing a spiral matrix pattern (hard)
    Eg:- Input - 4
         Output:- 1 2 3 4 
                  12 13 14 5 (The numbers will go in a spiral way)
                  11 26 15 6
                  10 9 8 7
*/
#include <stdio.h>// header files
#include <stdbool.h>

bool isZero(int n,int A[n][n])//function to check if any element of the matrix is zero
{
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++)
        {
            if(A[i][j] == 0)
            {
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    int n,count = 1;
    
    printf("Enter your number\n");
    scanf("%d",&n);//taking user input
    
    int A[n][n];
    
    for (int i = 0;i<n;i++)// setting all elements to zero
    {
        for (int j = 0;j<n;j++)
        {
            A[i][j] = 0;
        }
    }
    
    for (int i = 0;i<n;i++)// logic
    {
        if (i == 0)
        {
            for (int j = 0;j<n;j++)
            {
                A[i][j] = count;
                count++;
            }
        }
        
        else
        {
            for (int j = i;j<= n - i;j++)
            {
                A[j][n-i] = count;
                count++;
            }
            
            for (int j = n - i - 1;j>= i - 1;j--)
            {
                A[n-i][j] = count;
                count++;
            }
            
            for (int j = n - i - 1;j >= i;j--)
            {
                A[j][i - 1] = count;
                count++;
            }
            
            for (int j = i;j <= n - i - 1;j++)
            {
                A[i][j] = count;
                count++;
            }
        }
        
        if(!isZero(n,A))
        {
            break;
        }
    }
    
    for (int i = 0;i<n;i++)// displaying the matrix
    {
        for (int j = 0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}// Thank You my friend