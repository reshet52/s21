#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int fl = 1;
    while (n > 0 && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0) 
        fl = 0;
    return fl ? *(const unsigned char *)str1 - *(const unsigned char *)str2 : 0;
}
