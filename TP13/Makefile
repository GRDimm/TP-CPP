SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 

.PHONY: 2.1 2.2 2.3

clean:
	rm -f *.o *.h.gch *.test a.out

2.1.o: 2.1.h 2.1.cc
	$(GCC) -c 2.1.cc -o 2.1.o

2.1.test: 2.1.o main_utils.h 2.1.test.cc
	$(GCC) 2.1.o 2.1.test.cc -o 2.1.test

2.1: 2.1.test
	./2.1.test

2.2.o: 2.2.h 2.2.cc
	$(GCC) -c 2.2.cc -o 2.2.o

2.2.test: 2.1.o 2.2.o 2.3.o main_utils.h 2.2.test.cc
	$(GCC) 2.1.o 2.2.o 2.3.o 2.2.test.cc -o 2.2.test

2.2: 2.2.test
	./2.2.test

2.3.o: 2.3.h 2.3.cc
	$(GCC) -c 2.3.cc -o 2.3.o

2.3.test: 2.3.o main_utils.h 2.3.test.cc
	$(GCC) 2.3.o 2.3.test.cc -o 2.3.test

2.3: 2.3.test
	./2.3.test

2.4.test: 2.4.o main_utils.h 2.4.test.cc
	$(GCC) 2.4.o 2.4.test.cc -o 2.4.test

2.4: 2.4.test
	./2.4.test

2.5.o: 2.5.h 2.5.cc
	$(GCC) -c 2.5.cc -o 2.5.o

2.5.test: 2.5.o main_utils.h 2.5.test.cc
	$(GCC) 2.5.o 2.5.test.cc -o 2.5.test

2.5: 2.5.test
	./2.5.test

2.6.o: 2.6.h 2.6.cc
	$(GCC) -c 2.6.cc -o 2.6.o

2.6.test: 2.5.o 2.6.o main_utils.h 2.6.test.cc
	$(GCC) 2.5.o 2.6.o 2.6.test.cc -o 2.6.test

2.6: 2.6.test
	./2.6.test
