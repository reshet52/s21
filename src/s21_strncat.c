#include "s21_string.h"
char *s21_strcat(char *dest, const char *src, s21_size_t n) {
    int dest_len = s21_strlen(dest);
    int i = 0;

    for (; src[i] && n > 0; i++, n--) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}