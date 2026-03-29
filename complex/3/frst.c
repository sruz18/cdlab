#include<stdio.h>

void findFirst(char symbol);

int main()
{
    printf("FIRST(E) = { ");
    findFirst('E');
    printf(" }\n");

    printf("FIRST(T) = { ");
    findFirst('T');
    printf(" }\n");

    printf("FIRST(F) = { ");
    findFirst('F');
    printf(" }\n");

    return 0;
}

void findFirst(char symbol)
{
    switch(symbol)
    {
        case 'E':
            findFirst('T');
            break;

        case 'T':
            findFirst('F');
            break;

        case 'F':
            printf("( , id ");
            break;
    }
}