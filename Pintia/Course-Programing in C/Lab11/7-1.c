#include <stdio.h>
#include <string.h>

const int MAX_WORDS = 20;
const int MAX_LENGTH = 10;

typedef struct {
    char word[10 + 1];
    int index;
} Word;

void sort(Word words[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int len1 = strlen(words[j].word);
            int len2 = strlen(words[j + 1].word);
            if (len1 > len2 || (len1 == len2 && words[j].index > words[j + 1].index)) {
                Word temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    Word words[MAX_WORDS];
    int count = 0;

    while (count < MAX_WORDS) {
        char temp[MAX_LENGTH + 1];
        scanf("%s", temp);
        if (strcmp(temp, "#") == 0) break;
        strcpy(words[count].word, temp);
        words[count].index = count;
        count++;
    }

    sort(words, count);

    for (int i = 0; i < count; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");

    return 0;
}
