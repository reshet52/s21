#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test();

int main() {
    s21_strlen_test();
    return 0;
}

void s21_strlen_test() {
    const char *test_cases[] = {"Hello, World!", "", "a", "1234567890", "\0"};
    unsigned long expected_results[] = {13, 0, 1, 10, 0};

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int success_count = 0;

    for (int i = 0; i < num_tests; i++) {
        unsigned long result = s21_strlen(test_cases[i]);
        printf("\"%s\", %lu,  %s\n", test_cases[i], result,
               (result == expected_results[i]) ? "SUCCESS" : "FAIL");
        if (result == expected_results[i]) {
            success_count++;
        }
    }

    printf("Total tests: %d\n", num_tests);
    printf("Successful tests: %d\n", success_count);
}
