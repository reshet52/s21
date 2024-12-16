#include "s21_string.h"

s21_size_t strcspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    int found = 0;

    while (*str1 && !found) {
        const char *temp = str2;
        while (*temp && !found) {
            if (*str1 == *temp) {
                found = 1;
            }
            temp++;
        }
        if (!found) {
            len++;
        }
        str1++;
    }

    return len;
}
