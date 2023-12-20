SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 

.PHONY: 1.1 1.2

clean:
	rm -f *.o *.test

1.1.o: 1.1.h 1.1.cc
	$(GCC) -c 1.1.cc -o 1.1.o

1.1.test: 1.1.o main_utils.h 1.1.test.cc
	$(GCC) 1.1.o 1.1.test.cc -o 1.1.test

1.1: 1.1.test 1.1.test.sh
	./1.1.test.sh

1.2.o: 1.2.h 1.2.cc
	$(GCC) -c 1.2.cc -o 1.2.o

1.2.test: 1.2.o main_utils.h 1.2.test.cc
	$(GCC) 1.2.o 1.2.test.cc -o 1.2.test

1.2: 1.2.test 1.2.test.sh
	./1.2.test.sh

1.3.test: 1.2.o main_utils.h 1.3.test.cc
	$(GCC) 1.2.o 1.3.test.cc -o 1.3.test

1.3: 1.3.test 1.3.test.sh
	./1.3.test.sh

1.4.test: 1.4.o main_utils.h 1.4.test.cc
	$(GCC) 1.4.o 1.4.test.cc -o 1.4.test

1.4: 1.4.test 1.4.test.sh
	./1.4.test.sh
