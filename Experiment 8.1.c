#include <stdio.h>
int main()
{
    //Initializing variable.
    char str[100];
    int i,length=0;

    //Accepting input.
    printf("Enter a string: \n");
    scanf("%s",str);

    //Initializing for loop.
    for(i=0; str[i]!='\0'; i++)
    {
        length++; //Counting the length.
    }

    printf("\nLength of input string: %d",length);

    //Length using strlen() for verification
    {
        int strlen_manual = 0;
        const char *p = str;
        while (*p != '\0')
        {
            strlen_manual++;
            p++;
        }
        printf("\nLength verified with pointer traversal: %d", strlen_manual);
    }

    //Reverse and display the string, without using library functions
    printf("\nReverse of input string: ");
    for (i = length - 1; i >= 0; i--)
        putchar(str[i]);

    //Count vowels and consonants
    int vowels = 0, consonants = 0;
    for (i = 0; i < length; i++)
    {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
            ch = (char)(ch - 'A' + 'a');
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    printf("\nVowels: %d", vowels);
    printf("\nConsonants: %d", consonants);

    //Check whether the string is a palindrome
    int isPalindrome = 1;
    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - 1 - i])
        {
            isPalindrome = 0;
            break;
        }
    }
    //Note: the comparison is case sensitive, so "Malayalam" is not a palindrome
    printf("\n%s is %s palindrome (case sensitive)\n",
           str, isPalindrome ? "a" : "not a");

    return 0;
}
