all: strlen_tests strcmp_tests strcpy_tests strcat_tests clean

strlen_tests: s21_string s21_string_test
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test.o -o ../build/Quest_1

s21_string: s21_string.c
	gcc -Wall -Werror -Wextra -c s21_string.c

s21_string_test: s21_string_test.c
	gcc -Wall -Werror -Wextra -c s21_string_test.c -Dfunc=s21_strlen_test

strcmp_tests: s21_stringcmp s21_stringcmp_test
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test.o -o ../build/Quest_2

s21_stringcmp: s21_string.c
	gcc -Wall -Werror -Wextra -c s21_string.c

s21_stringcmp_test: s21_string_test.c
	gcc -Wall -Werror -Wextra -c s21_string_test.c -Dfunc=s21_strcmp_test

strcpy_tests: s21_stringcmp s21_stringcmp_test
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test.o -o ../build/Quest_3

s21_stringcpy: s21_string.c
	gcc -Wall -Werror -Wextra -c s21_string.c

s21_stringcpy_test: s21_string_test.c
	gcc -Wall -Werror -Wextra -c s21_string_test.c -Dfunc=s21_strcmp_test

strcat_tests: s21_stringcat s21_stringcat_test
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test.o -o ../build/Quest_4

s21_stringcat: s21_string.c
	gcc -Wall -Werror -Wextra -c s21_string.c

s21_stringcat_test: s21_string_test.c
	gcc -Wall -Werror -Wextra -c s21_string_test.c -Dfunc=s21_strcat_test

clean: 
	rm -rf *.o