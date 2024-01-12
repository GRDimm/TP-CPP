SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 

.PHONY: 1.1 1.2 1.3 2.1 2.2 2.3

clean:
	rm -f *.o *.h.gch *.test a.out

1.1.o: 1.1.h 1.1.cc
	$(GCC) -c 1.1.cc -o 1.1.o

1.1.test: 1.1.o main_utils.h 1.1.test.cc
	$(GCC) 1.1.o 1.1.test.cc -o 1.1.test

1.1: 1.1.test
	./1.1.test

2.1.o: 2.1.h 2.1.cc
	$(GCC) -c 2.1.cc -o 2.1.o

2.1.test: 2.1.o main_utils.h 2.1.test.cc
	$(GCC) 2.1.o 2.1.test.cc -o 2.1.test

2.1: 2.1.test
	./2.1.test

2.2.o: 2.2.h 2.2.cc
	$(GCC) -c 2.2.cc -o 2.2.o

2.2.test: 2.2.o main_utils.h 2.2.test.cc
	$(GCC) 2.2.o 2.2.test.cc -o 2.2.test

2.2: 2.2.test
	./2.2.test

2.3.test: 2.3.h main_utils.h 2.3.test.cc
	$(GCC) 2.3.test.cc -o 2.3.test

2.3: 2.3.test
	./2.3.test
