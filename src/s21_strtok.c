#include "s21_string.h"
char *s21_strtok(char *str, const char *delim) {
    static char *next_token = s21_NULL;
    char *token;
    int fl = 1;
    if (str != s21_NULL) {
        next_token = str;
    }

    if (next_token == s21_NULL) {
        fl = 0;
    }

    while (*next_token != '\0' && s21_strchr(delim, *next_token) != NULL) {
        next_token++;
    }

    if (*next_token == '\0') {
        fl = 0;
    }

    token = next_token;

    while (*next_token != '\0' && s21_strchr(delim, *next_token) == NULL) {
        next_token++;
    }

    if (*next_token != '\0') {
        *next_token++ = '\0';
    }

    return fl? token : s21_NULL;
}