#include <stdio.h>
#include <string.h>

#define MAX 50

struct Symbol {
    char label[50];
    int address;
};

struct Symbol table[MAX];
int count = 0;

// SEARCH FUNCTION
int search(char lab[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].label, lab) == 0) {
            return i;
        }
    }
    return -1;
}

// INSERT
void insert() {
    char lab[50];
    int addr;

    printf("Enter symbol (label): ");
    scanf("%s", lab);

    int pos = search(lab);

    if (pos != -1) {
        printf("Duplicate Symbol\n");
        return;
    }

    printf("Enter address: ");
    scanf("%d", &addr);

    strcpy(table[count].label, lab);
    table[count].address = addr;
    count++;

    printf("Symbol inserted successfully\n");
}

// DISPLAY
void display() {
    if (count == 0) {
        printf("Symbol table is empty\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("Label\tAddress\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%d\n", table[i].label, table[i].address);
    }
}

// DELETE
void deleteSymbol() {
    char lab[50];
    printf("Enter symbol to delete: ");
    scanf("%s", lab);

    int pos = search(lab);

    if (pos == -1) {
        printf("Label Not found\n");
        return;
    }

    for (int i = pos; i < count - 1; i++) {
        table[i] = table[i + 1];
    }

    count--;
    printf("Symbol deleted successfully\n");
}

// MODIFY
void modify() {
    char lab[50];
    printf("Enter symbol to modify: ");
    scanf("%s", lab);

    int pos = search(lab);

    if (pos == -1) {
        printf("Label Not found\n");
        return;
    }

    int choice;
    printf("1. Modify Label\n2. Modify Address\n3. Modify Both\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 3) {
        char newlab[50];
        printf("Enter new label: ");
        scanf("%s", newlab);

        if (search(newlab) != -1) {
            printf("Duplicate Symbol\n");
            return;
        }

        strcpy(table[pos].label, newlab);
    }

    if (choice == 2 || choice == 3) {
        int newaddr;
        printf("Enter new address: ");
        scanf("%d", &newaddr);

        table[pos].address = newaddr;
    }

    printf("Symbol modified successfully\n");
}

// MAIN
int main() {
    int choice;

    while (1) {
        printf("\n--- Symbol Table Menu ---\n");
        printf("1. Insert\n2. Display\n3. Delete\n4. Search\n5. Modify\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                deleteSymbol();
                break;

            case 4: {
                char lab[50];
                printf("Enter symbol to search: ");
                scanf("%s", lab);

                int pos = search(lab);
                if (pos == -1) {
                    printf("Symbol not found\n");
                } else {
                    printf("Found: %s at address %d\n",
                           table[pos].label,
                           table[pos].address);
                }
                break;
            }

            case 5:
                modify();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}