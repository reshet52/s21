#include "s21_string.h"
char *s21_strcpy(char *dest, const char *src, s21_size_t n) {
    int i = 0;
    while (*(src + i) != '\0' && n > 0) {
        *(dest + i) = *(src + i);
        i++;
        n--;
    }
    return dest;
}