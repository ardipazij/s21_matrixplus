OS := $(shell uname)
CC = -Wall -Werror -Wextra -lstdc++ -std=c++17
FLAGS = -lgtest -ftest-coverage -fprofile-arcs

ifeq ($(OS),Darwin)
	OPEN_CMD = open
else
	FLAGS += -lm -lrt -lsubunit
	OPEN_CMD = xdg-open
endif

all: clean s21_matrix_oop.a test

s21_matrix_oop.a:
	gcc $(CC) -c s21_matrix_oop.cc
	ar -crs s21_matrix_oop.a s21_matrix_oop.o

test: clean s21_matrix_oop.a
	gcc $(CC) tests/test.cc s21_matrix_oop.a $(FLAGS) -o test
	./test

gcov_report: clean
	gcc $(CC) tests/test.cc s21_matrix_oop.cc $(FLAGS) -o test
	./test
	lcov -t "./test"  -o report.info --no-external --ignore-errors mismatch -c -d .
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html

	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o *.a test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info