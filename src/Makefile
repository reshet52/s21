CC = gcc -Wall -Wextra -Werror
strlen_tests.o: s21_test.o s21_strlen.o
	$(CC) s21_test.o s21_strlen.o -o s21_test_len
s21_strlen.o: s21_strlen.c
	$(CC) s21_strlen.c -c
clean:
	rm *.o
unit_tests: 
	gcc -o tests s21_unit_tests.c s21_memchr.c s21_strlen.c $(pkg-config --cflags --libs check)