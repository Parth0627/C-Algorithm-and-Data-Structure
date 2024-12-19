/*
    Coded by Parth Pandya
    Problem Statement:- Here we are solving a particular string pattern 
    Eg:-   Input : 12345
           Output:1   5
                   2 4 
                    3  
                   2 4 
                  1   5
*/ 
#include <stdio.h>// header files
#include <string.h>

int main()
{
    char a[100];//strings
    char b[100];
    char t;
    int temp;
    
    printf("Enter your string\n");
    fgets(a,sizeof(a),stdin);// taking input
    
    strcpy(b,a);// copy string a in b
    
    temp = strlen(b);
    a[temp - 1] = '\0';// doing this as fgets also takes newline as input
    b[temp - 1] = '\0';
    
    for (int i = 0;i<strlen(b)/2;i++)//logic
    {
        t = b[i];
        b[i] = b[strlen(b) - i - 1];
        b[strlen(b) - i - 1] = t;
    }
    
    for (int i = 0;i<strlen(a);i++)
    {
        if (i < (strlen(a) - 1)/2)
        {
        for (int j = 0;j<i;j++)
        {
            printf(" ");
        }
           printf("%c",a[i]);
           
           for (int k = 0;k<strlen(a) - (2*i) - 2;k++)
           {
               printf(" ");
           }
           printf("%c",b[i]);
           printf("\n");
        }
        
        else if (i == (strlen(a) - 1)/2)
        {
            for (int j = 0;j<i;j++)
            {
                printf(" ");
            }
            printf("%c",a[i]);
            printf("\n");
        }
        
        else if (i > (strlen(a) - 1)/2)
        {
            temp = strlen(a) - i;
            
            for (int j = 0;j<temp - 1;j++)
            {
                printf(" ");
            }
            printf("%c",b[i]);
            
            for (int k = 0;k< strlen(a) - (temp*2);k++)
            {
                printf(" ");
            }
            printf("%c",a[i]);
            printf("\n");
        }
    }
    return 0;
}// Thank You my Friend