SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 

.PHONY: 1.1 1.2 1.3 2.1 3.1

clean:
	rm -f *.o *.h.gch *.test *.bin a.out 1.3.patched.cc small5 big generate_big_file

1.1.bin: 1.1.cc
	$(GCC) 1.1.cc -o 1.1.bin

1.1: 1.1.bin 1.1.test.sh
	./1.1.test.sh

1.2.bin: 1.2.cc
	$(GCC) 1.2.cc -o 1.2.bin

1.2: 1.2.bin 1.2.test.sh
	./1.2.test.sh

1.3.patched.cc: 1.3.cc 1.3.patch.sh
	./1.3.patch.sh

1.3.bin: 1.3.patched.cc
	$(GCC) 1.3.cc -o 1.3.tmp.bin && $(GCC) 1.3.patched.cc -o 1.3.bin

generate_big_file: generate_big_file.cc
	$(GCC) generate_big_file.cc -o generate_big_file

1.3: 1.3.bin 1.3.test.sh generate_big_file
	./1.3.test.sh
	rm -f small5 big 2> /dev/null || echo -n ""

2.1.o: 2.1.h 2.1.cc
	$(GCC) -c 2.1.cc -o 2.1.o

2.1.test: 2.1.o main_utils.h 2.1.test.cc
	$(GCC) 2.1.o 2.1.test.cc -o 2.1.test

2.1: 2.1.test 2.1.test.sh
	./2.1.test && bash ./2.1.test.sh


3.1.o: 3.1.h 3.1.cc
	$(GCC) -c 3.1.cc -o 3.1.o

3.1.test: 3.1.o main_utils.h 3.1.test.cc
	$(GCC) 3.1.o 3.1.test.cc -o 3.1.test

3.1: 3.1.test
	./3.1.test
