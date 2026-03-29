#include<stdio.h>
#include<stdlib.h>

char input[100];
int position = 0;

char getChar();
void error();
int parseS();
int parseL();

char getChar(){
    return input[position];
}

void error(){
    printf("Error at position %d\n", position);
    exit(0);
}

// S -> a | (L)
int parseS(){
    if(getChar() == 'a'){
        position++;
        return 1;
    }
    else if(getChar() == '('){
        position++;
        if(!parseL()) error();
        if(getChar() == ')'){
            position++;
            return 1;
        }
        else error();
    }
    return 0;
}

// L -> S { , S }
int parseL(){
    if(!parseS()) return 0;

    while(getChar() == ','){
        position++;
        if(!parseS()) error();
    }
    return 1;
}

int main(){
    printf("Enter input string: ");
    scanf("%s", input);

    if(parseS() && input[position] == '\0')
        printf("Valid string\n");
    else
        error();

    return 0;
}