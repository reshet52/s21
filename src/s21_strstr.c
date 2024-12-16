#include "s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
    int fl = 1;
    if (*needle != '\0') {
        fl = 0;
    }

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (*n != '\0') {
            fl = 0;
        }

        haystack++;
    }

    return fl ? (char *)haystack : s21_NULL;
}