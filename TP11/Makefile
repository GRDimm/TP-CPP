SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 

.PHONY: 2.1 3.1 3.2 3.3

clean:
	rm -f *.o *.test a.out

2.1.o: 2.1.h 2.1.cc
	$(GCC) -c 2.1.cc -o 2.1.o

2.1.test: 2.1.o main_utils.h 2.1.test.cc
	$(GCC) 2.1.o 2.1.test.cc -o 2.1.test

2.1: 2.1.test
	./2.1.test

3.1.test: 3.1.h main_utils.h 3.1.test.cc
	$(GCC) 3.1.test.cc -o 3.1.test

3.1: 3.1.test 3.1.test.sh
	./3.1.test.sh

3.2.test: 3.2.h main_utils.h 3.2.test.cc
	$(GCC) 3.2.test.cc -o 3.2.test

3.2: 3.2.test 3.2.test.sh
	./3.2.test.sh

3.3.test: 3.3.h main_utils.h 3.3.test.cc
	$(GCC) 3.3.test.cc -o 3.3.test

3.3: 3.3.test 3.3.test.sh
	./3.3.test.sh