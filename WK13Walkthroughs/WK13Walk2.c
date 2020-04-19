/*-------------------------------------------------
// Walkthrough Practice Question-2
-------------------------------------------------*/

#include<stdio.h>
#include<string.h>

char getCharVal(const char *str, int pos)
{
    return (char)str[pos] + 2;
}

int main(void)
{
    int i, len;
    char str[5][21] = { "Cat", "Dogs", "Birds", "Turkey", "Elephant" };

    for (i = 0; i < 5; i++) {

        len = strlen(str[i]);

        printf("%d:%d-%c", i, len,
            (len - i) % 2 == 0 ? getCharVal(str[i], len - 2) : getCharVal(str[i], 2));

        puts("");
    }

    puts("");
    
    return 0;
}
