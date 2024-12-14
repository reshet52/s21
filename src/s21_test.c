#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <s21_string.h>

// Прототипы функций
void *s21_memchr(const void *str, int c, s21_size_t n);
s21_size_t s21_strlen(const char *str);

// Тесты для s21_memchr
START_TEST(test_s21_memchr_found)
{
    const char str[] = "hello";
    ck_assert_ptr_eq(s21_memchr(str, 'e', sizeof(str)), memchr(str, 'e', sizeof(str)));
}
END_TEST

START_TEST(test_s21_memchr_not_found)
{
    const char str[] = "hello";
    ck_assert_ptr_eq(s21_memchr(str, 'x', sizeof(str)), memchr(str, 'x', sizeof(str)));
}
END_TEST

START_TEST(test_s21_memchr_empty_string)
{
    const char str[] = "";
    ck_assert_ptr_eq(s21_memchr(str, 'a', sizeof(str)), memchr(str, 'a', sizeof(str)));
}
END_TEST

// Тесты для s21_strlen
START_TEST(test_s21_strlen_empty)
{
    const char str[] = "";
    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_non_empty)
{
    const char str[] = "hello";
    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_single_char)
{
    const char str[] = "a";
    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *s21_memchr_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("S21Memchr");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_memchr_found);
    tcase_add_test(tc_core, test_s21_memchr_not_found);
    tcase_add_test(tc_core, test_s21_memchr_empty_string);
    suite_add_tcase(s, tc_core);

    return s;
}

// Suite для s21_strlen
Suite *s21_strlen_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("S21Strlen");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_strlen_empty);
    tcase_add_test(tc_core, test_s21_strlen_non_empty);
    tcase_add_test(tc_core, test_s21_strlen_single_char);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s1, *s2;
    SRunner *sr;

    s1 = s21_memchr_suite();
    s2 = s21_strlen_suite();
    sr = srunner_create(s1);
    srunner_add_suite(sr, s2);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
