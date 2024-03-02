#include <iostream>
#include <cstring>

char* gets(char* s) {
    char c;
    int i = 0;
    while ((c = std::cin.get()) != '\n' && i < 99) {
        if (isalpha(c)) {
            s[i++] = c;
        }
    }
    s[i] = '\0';
    return s;
}

int puts(const char* s) {
    std::cout << s << std::endl;
    return 0;
}

bool vowel(char c) {
    char vowels[] = "aeiouyAEIOUY";
    for (int i = 0; i < strlen(vowels); ++i) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}

void removeVowel(char* str) {
    char* word = strtok_s(str, " ", &str);
    while (word != nullptr) {
        int len = strlen(word);
        if (vowel(word[len - 1])) {
            *word = '\0';
        }
        word = strtok_s(nullptr, " ", &str);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    char str[100];
    puts("Введите строку:");
    gets(str);
    removeVowel(str);
    puts("Строка после удаления слов, заканчивающихся на гласную букву:");
    puts(str);
    return 0;
}
