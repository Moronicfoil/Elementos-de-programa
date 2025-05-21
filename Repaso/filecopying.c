#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        
    }
    printf("%d",c);
    return 0;
}
