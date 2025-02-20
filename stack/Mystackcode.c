#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 100

void insertword() {
    char myword[MAX];
    printf("\n Write down a word of your choice: \n");
    fgets(myword, sizeof(myword), stdin);
    myword[strcspn(myword, "\n")] = '\0';  // Remover a quebra de linha

    int size = strlen(myword);
    int sizetochange = size - 1;
    char newword[MAX];

    for (int a = 0; a < size; a++) {
        newword[a] = myword[sizetochange];
        sizetochange--;
    }
    newword[size] = '\0';  // Adiciona o terminador de string

    printf("\n Your reversed word: %s\n", newword);
}

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    insertword();
    return 0;
}
