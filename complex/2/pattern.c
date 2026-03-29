#include<stdio.h>
#include<ctype.h>
#include<string.h>

int isKeyword(char str[]) {
    char *kw[] = {"int","float","char","if","else","for","while","return"};
    for(int i=0;i<8;i++)
        if(strcmp(str,kw[i])==0) return 1;
    return 0;
}

int main() {
    char ch, word[20];
    int i=0, line=1;

    printf("Enter program (Ctrl+D to stop):\n");

    while((ch=getchar())!=EOF) {

        if(ch=='\n') line++;

        /* identifier or keyword */
        if(isalpha(ch)) {
            i=0;
            word[i++]=ch;

            while(isalnum(ch=getchar()) || ch=='_')
                word[i++]=ch;

            word[i]='\0';

            if(isKeyword(word))
                printf("Keyword: %s\n",word);
            else
                printf("Identifier: %s\n",word);

            ungetc(ch,stdin);
        }

        /* number */
        else if(isdigit(ch)) {
            printf("Number: %c\n",ch);
        }

        /* operator / special symbol */
        else if(!isspace(ch)) {
            printf("Operator: %c\n",ch);
        }
    }

    printf("Lines: %d\n",line);
}