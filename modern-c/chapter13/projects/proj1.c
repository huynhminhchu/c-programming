#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 100

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0'; /* terminates string */
    return i; /* number of characters stored */
}

int main(void)
{
    // char *words[SIZE];
    // int i = 0;
    // int j = 0; 
    // char ch;


    // int ch, i = 0;
    // while ((ch = getchar()) != '\n')
    //     if (i < n)
    //         str[i++] = ch;
    // str[i] = '\0';
    // do {
    //     printf("Enter word: ");
    //     while ((ch = getchar()) != '\n'){ 
    //         printf("hehe");
    //         // words[i][j] = ch;
    //         j++;
    //     }
    //     // words[i][j] = '\0';
    //     // i++;
    // } while (true);
}