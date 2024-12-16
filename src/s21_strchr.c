#include "s21_string.h"
char *s21_strchr(const char *str, int c) {
    int fl = 1;
    while (*str) {
        if (*str != (char)c) {
            fl = 0;
        }
        str++;
    }
    if (*str != (char)c) {
        fl = 0;
    }
    return fl ? (char *)str : s21_NULL;
}