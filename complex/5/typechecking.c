
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isInteger(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int isFloat(char str[]) {
    int dot = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') dot++;
        else if (!isdigit(str[i])) return 0;
    }
    return (dot == 1);
}

int main() {
    char type[10], var[10], value[20];

    printf("Enter declaration (e.g., int a = 10):\n");
    scanf("%s %s = %s", type, var, value);

    if (strcmp(type, "int") == 0) {
        if (isInteger(value))
            printf("Valid assignment\n");
        else
            printf("Type Error\n");
    }

    else if (strcmp(type, "float") == 0) {
        if (isFloat(value) || isInteger(value))
            printf("Valid assignment\n");
        else
            printf("Type Error\n");
    }

    else if (strcmp(type, "char") == 0) {
        if (strlen(value) == 3 && value[0] == '\'' && value[2] == '\'')
            printf("Valid assignment\n");
        else
            printf("Type Error\n");
    }

    else {
        printf("Unknown Type\n");
    }

    return 0;
}