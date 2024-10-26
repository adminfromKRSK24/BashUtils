CC = gcc
CFLAGS = 
UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	CTEST= 				
else
	CTEST=
endif
ARGS = -b test.txt test_2.txt

all : cat

rebuild: clean all

test: clean cat
	cat test.txt > origin_f.txt && ./cat test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat test.txt test_2.txt > origin_f.txt && ./cat test.txt test_2.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -b test.txt > origin_f.txt && ./cat -b test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -b test.txt test_2.txt > origin_f.txt && ./cat -b test.txt test_2.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -e test.txt > origin_f.txt && ./cat -e test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -v bytes.txt > origin_f.txt && ./cat -v bytes.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -n test.txt > origin_f.txt && ./cat -n test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -s test.txt > origin_f.txt && ./cat -s test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -t test.txt > origin_f.txt && ./cat -t test.txt > my_f.txt && diff origin_f.txt my_f.txt

test_linux: clean cat
	cat --number-nonblank test.txt > origin_f.txt && ./cat --number-nonblank ./files/text.txt ./files/text2.txt > ./files/my.txt && diff ./files/std.txt ./files/my.txt
	cat --number test.txt > origin_f.txt && ./cat --number test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat --squeeze-blank test.txt > origin_f.txt && ./cat --squeeze-blank test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -T test.txt > origin_f.txt && ./cat -T test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat -E test.txt > origin_f.txt && ./cat -E test.txt > my_f.txt && diff origin_f.txt my_f.txt
	cat --show-nonprinting bytes.txt > origin_f.txt && ./cat --show-nonprinting bytes.txt > my_f.txt && diff origin_f.txt my_f.txt

cat :
	$(CC) $(CFLAGS) cat.c -o cat

run:
	./cat $(ARGS)

valg:
	$(CC) -g cat.c -o cat
	valgrind --track-origins=yes -q ./cat $(ARGS)

clean:
	rm -f *.html *.o *.a *.gcno *.gcda *.info *.out *.css
	rm -rf ./report
	rm -f cat
	rm -f ./files/my.txt
	rm -f ./files/std.txt
	rm -rf *.dSYM
	clear

cpplint:
	python3 ../../materials/linters/cpplint.py --extensions=c cat.c
	python3 ../../materials/linters/cpplint.py --extensions=c cat.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem cat.c
	cppcheck --enable=all --suppress=missingIncludeSystem cat.h

leaks:
	$(CC) -Wall -Werror -Wextra -lm cat.c -o cat
	leaks -atExit -- ./cat -b test.txt
	leaks -atExit -- ./cat -e test.txt
	leaks -atExit -- ./cat -n test.txt
	leaks -atExit -- ./cat -s test.txt
	leaks -atExit -- ./cat -t test.txt
	leaks -atExit -- ./cat -v test.txt