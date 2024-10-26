CC = gcc
CFLAGS = 
UNAME = $(shell uname)
FILE = grep

ifeq ($(UNAME), Linux)
	CTEST = 
else
	CTEST = 
endif

all : grep

test :
	./grep -e on test.txt y_test.txt > my_test.txt && grep -e on test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -e on test.txt > my_test.txt && grep -e on test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -i oN test.txt > my_test.txt && grep -i oN test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -i oN test.txt y_test.txt > my_test.txt && grep -i oN test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -v o test.txt > my_test.txt && grep -v o test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -v o test.txt y_test.txt > my_test.txt && grep -v o test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -c on test.txt > my_test.txt && grep -c on test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -c on test.txt y_test.txt > my_test.txt && grep -c on test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -l o test.txt > my_test.txt && grep -l o test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -l o test.txt y_test.txt > my_test.txt && grep -l o test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -n on test.txt y_test.txt > my_test.txt && grep -n on test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -h on test.txt y_test.txt > my_test.txt && grep -h on test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -s on test.txt > my_test.txt && grep -s on test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -f test_pattern.txt test.txt > my_test.txt && grep -f test_pattern.txt test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -f test_pattern.txt test.txt test.txt > my_test.txt && grep -f test_pattern.txt test.txt test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -o teen test.txt > my_test.txt && grep -o teen test.txt > orig_test.txt && diff my_test.txt orig_test.txt
	./grep -o teen test.txt y_test.txt > my_test.txt && grep -o teen test.txt y_test.txt > orig_test.txt && diff my_test.txt orig_test.txt

run :
# ./grep -f test_pattern.txt test.txt y_test.txt > my_test.txt

grep:
	$(CC) $(CFLAGS) grep.c -o grep 

cpplint:
	python3 ../../materials/linters/cpplint.py --extensions=c $(FILE).c
	python3 ../../materials/linters/cpplint.py --extensions=c $(FILE).h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILE).c
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILE).h

leaks:
	$(CC) -Wall -Werror -Wextra -lm $(FILE).c -o $(FILE)
	leaks -atExit -- ./$(FILE)

valg:
	$(CC) -g $(FILE).c -o $(FILE)
	valgrind --track-origins=yes -q ./$(FILE)

clean :
	rm -rf ./grep *.o