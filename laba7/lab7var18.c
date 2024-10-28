#include <stdio.h>
#include <string.h>

int main() {
char sentence[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
char word_with_max_a[100];
int max_a_count = 0;
char *word = strtok(sentence, " ,.\"");
while (word != NULL) {
    int a_count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == 'a' || word[i] == 'A') {
            a_count++;
        }
    }
    if (a_count > max_a_count) {
        max_a_count = a_count;
        strcpy(word_with_max_a, word);
    }
    word = strtok(NULL, " ,.\"");
}

printf("Слово с максимальным кол-вом 'a': %s\n", word_with_max_a);
printf("Количество 'a' в слове: %d\n", max_a_count);

return 0;
}
