#include<stdio.h>
#include<ctype.h>

char production[10][10], result[10];
int count, size = 0;

int alreadyPresent(char ch){
    for(int i=0;i<size;i++)
        if(result[i]==ch) return 1;
    return 0;
}

void findFirst(char symbol){
    for(int i=0;i<count;i++){
        if(production[i][0] == symbol){

            for(int j=2; production[i][j] != '\0'; j++){
                char next = production[i][j];

                if(!isupper(next)){   // terminal
                    if(!alreadyPresent(next))
                        result[size++] = next;
                    break;
                }
                else{                 // non-terminal
                    findFirst(next);
                    break;  // simplified (no full epsilon chain handling)
                }
            }
        }
    }
}

int main(){
    int choice;
    char symbol;

    printf("Enter number of productions: ");
    scanf("%d",&count);

    printf("Enter productions:\n");
    for(int i=0;i<count;i++)
        scanf("%s",production[i]);

    do{
        size = 0;

        printf("\nEnter non-terminal: ");
        scanf(" %c",&symbol);

        findFirst(symbol);

        printf("FIRST(%c) = { ",symbol);
        for(int i=0;i<size;i++)
            printf("%c ",result[i]);
        printf("}\n");

        printf("1-continue 0-exit: ");
        scanf("%d",&choice);

    }while(choice==1);
}