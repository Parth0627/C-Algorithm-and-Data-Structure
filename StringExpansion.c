/*
     Coded by Parth Pandya
     Problem statement:- To take a string input in a format like a2b4 and thus the output will be aabbbb.
     Eg:- Input:- a1b4c5de
          Output:- abbbbcccccde
 */

#include <stdio.h>//header files
#include <string.h>//to use function like strlen
#include <ctype.h>//to use function like isdigit

int main()
{
    int k = 0;
    char s[100];
    
    printf("Enter your string as per the required questions format\n");
    fgets(s,sizeof(s),stdin);//taking the full string input
    
    char temp[100] = {0};
     
    for (int i = 0;i<strlen(s);i++)// logic
    {
        if (!isdigit((unsigned char)s[i]))// i used unsigned char as the isdigit requires an integer to be compared and no negative values
        {
            temp[k] = s[i];
            k++;
            
        }
        
        else
        {
            int z = s[i] - '0';
            temp[k] = '\0';
            for (int j = 0;j<z;j++)
            {
            printf("%s",temp);
            }

            k = 0;
        }
        
    }
    
    if (strlen(temp) > 0)// printing the remaining string
    {
        printf("%s",temp);
    }
    
    return 0;
}// Thank You my friend
