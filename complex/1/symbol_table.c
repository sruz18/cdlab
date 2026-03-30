#include <stdio.h>
#include <string.h>

struct sym {
    char name[20];
    int addr;
} s[50];

int n = 0;

// search
int search(char name[]) {
    for(int i = 0; i < n; i++)
        if(strcmp(s[i].name, name) == 0)
            return i;
    return -1;
}

int main() {
    int ch, pos;
    char name[20];

    while(1) {
        printf("\n1.Insert 2.Display 3.Search 4.Delete 5.Modify 6.Exit\n");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Enter name and address: ");
            scanf("%s %d", s[n].name, &s[n].addr);
            n++;
        }

        else if(ch == 2) {
            for(int i = 0; i < n; i++)
                printf("%s %d\n", s[i].name, s[i].addr);
        }

        else if(ch == 3) {
            printf("Enter name: ");
            scanf("%s", name);
            pos = search(name);
            if(pos == -1) printf("Not found\n");
            else printf("Found at %d\n", s[pos].addr);
        }

        else if(ch == 4) {
            printf("Enter name: ");
            scanf("%s", name);
            pos = search(name);
            if(pos != -1) {
                for(int i = pos; i < n-1; i++)
                    s[i] = s[i+1];
                n--;
            }
        }

        else if(ch == 5) {
            printf("Enter name: ");
            scanf("%s", name);
            pos = search(name);
            if(pos != -1) {
                printf("Enter new address: ");
                scanf("%d", &s[pos].addr);
            }
        }

        else if(ch == 6) break;
    }

    return 0;
}