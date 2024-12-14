#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *p = str;
    void *result = s21_NULL;
    s21_size_t i = 0;
    while (i < n && result == s21_NULL) {
        if (p[i] == (unsigned char)c) {
            result = (void *)(p + i);
        }
        i++;
    }
    return result;
}