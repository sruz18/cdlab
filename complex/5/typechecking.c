#include <stdio.h>
#include <string.h>

int main()
{
    char type1[10], type2[10], op;

    printf("Enter first operand type (int/float/char): ");
    scanf("%s", type1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second operand type (int/float/char): ");
    scanf("%s", type2);

    // Type checking
    if(strcmp(type1,"int")==0 && strcmp(type2,"int")==0)
    {
        printf("Valid Expression: Result type is int\n");
    }
    else if((strcmp(type1,"int")==0 && strcmp(type2,"float")==0) ||
            (strcmp(type1,"float")==0 && strcmp(type2,"int")==0) ||
            (strcmp(type1,"float")==0 && strcmp(type2,"float")==0))
    {
        printf("Valid Expression: Result type is float\n");
    }
    else if(strcmp(type1,"char")==0 || strcmp(type2,"char")==0)
    {
        printf("Type Error: Operation not allowed with char type\n");
    }
    else
    {
        printf("Invalid Types\n");
    }

    return 0;
}
