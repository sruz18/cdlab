#include<stdio.h>
#include<stdlib.h>

char input[100];
int pos = 0;

/* function declarations */
char getChar();
void error();
void E();
void Ep();
void T();
void Tp();
void F();

/* function definitions */
char getChar(){ return input[pos]; }

void error(){
    printf("Error at position %d\n", pos);
    exit(0);
}

void E(){ T(); Ep(); }

void Ep(){
    if(getChar()=='+'){
        pos++;
        T();
        Ep();
    }
}

void T(){ F(); Tp(); }

void Tp(){
    if(getChar()=='*'){
        pos++;
        F();
        Tp();
    }
}

void F(){
    if(getChar()=='('){
        pos++;
        E();
        if(getChar()==')') pos++;
        else error();
    }
    else if(getChar()=='i'){
        pos++;
    }
    else{
        error();
    }
}

int main(){
    printf("Enter expression: ");
    scanf("%s", input);

    E();

    if(input[pos]=='\0')
        printf("Valid expression\n");
    else
        error();

    return 0;
}