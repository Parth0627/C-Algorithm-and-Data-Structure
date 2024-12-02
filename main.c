/*
    Coded by :- Parth Pandya
    Problem statement:- The Problem is to print words in a sentence after each whitespace.The limits of the string is 1 <= length <= 1000.
     Eg:- Input:- "Hi i am Parth"
          Output :- Hi
                    i
                    am
                    Parth
 */

#include <stdio.h>//header files
#include <string.h>

int main()
{
    char c[1000];//input statement string
    char s[1000];//tempory string to store and print
    
    printf("Enter your statement\n");
    fgets(c,sizeof(c),stdin);//taking whole sentence as input 
    
    if (strlen(c) < 2 || strlen(c) > 1000)//limits taking 2 as 1 space is always occupied by the null terminator
    {
        printf("Please enter a string of length range 1 <= len <= 1000\n");
    }
    
    for (int i = 0;i<strlen(c);i++)//logic
    {
        if (c[i] != ' ')
        {
            int len = strlen(s);
            s[len] = c[i];
            s[len + 1] = '\0';
            
        }
        else
        {
            printf("%s\n",s);
           s[0] = '\0';
        }
    }
    
    if (strlen(s) > 0)// if any other word is left
    {
        printf("%s\n",s);
    }
    
    return 0;
}// Thank you my friend