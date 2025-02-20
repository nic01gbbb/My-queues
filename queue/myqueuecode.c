#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 4

char queue[MAX][50];
int start = 0;
int end = 0;

void addqueue() {
    char name[50];

    if ((end + 1) % MAX == start) {
        printf("\n I’m sorry, but your queue has reached the limit\n");
        return;
    }

    printf("\nChoose a name to add to your queue\n");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    strcpy(queue[end], name);
    end = (end + 1) % MAX;

    printf("\n%s added to your list \n", name);
}

void removeinqueue() {
    if (end == start) {
        printf("\n Sorry, but your list is empty. Add new elements\n");
        return;
    }

    char nameRight[50];
    strcpy(nameRight, queue[start]);
    printf("\nHey %s, all right to close here, please\n", nameRight);

    start = (start + 1) % MAX;
    printf("\nCustomer on position %d, SR: %s, removed successfully\n", start, nameRight);
}

void listinqueue() {
    if (end == start) {
        printf("\n Your list is empty, add new elements\n");
        return;
    }

    for (int a = 0; a < end; a++) {
        printf("\n %s \n", queue[a]);
    }
}

void searchsomeone() {
    char nameSearch[55];
    printf("\nIn order to search for someone, put their name here and we will try to find them\n");
    getchar();
    fgets(nameSearch, sizeof(nameSearch), stdin);
    nameSearch[strcspn(nameSearch, "\n")] = '\0';

    int exists = -1;
    for (int a = 0; a < end; a++) {
        if (strcmp(queue[a], nameSearch) == 0) {
            exists = a;
        }
    }

    if (exists == -1) {
        printf("\nSorry, but we did not find anyone with that name\n");
        return;
    }
    printf("\nThe person you’re trying to find is %s, at position %d\n", nameSearch, exists);
}

void menu() {
    int chose;
    do {
        printf("\nChoose a service to use\n");
        printf("\n1. Include a new name in your list\n");
        printf("\n2. Remove a name from your list\n");
        printf("\n3. List your entire queue\n");
        printf("\n4. Search for someone in the queue\n");
        printf("\n5. Cancel the operation\n");
        printf("\n");
        scanf("\n %d", &chose);

        switch (chose) {
            case 1:
                addqueue();
                break;
            case 2:
                removeinqueue();
                break;
            case 3:
                listinqueue();
                break;
            case 4:
                searchsomeone();
                break;
            case 5:
                break;
            default:
                printf("\nInvalid Option\n");
        }
    } while (chose != 5);
}

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    menu();
    return 0;
}
