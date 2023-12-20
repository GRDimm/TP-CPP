SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 

.PHONY: 2.1 2.2 2.3 3.1 3.2 3.3 3.4 4.1 4.2 4.3 4.4 4.5

clean:
	rm -f *.o *.h.gch *.test a.out

2.1.test: 2.1.h main_utils.h 2.1.test.cc
	$(GCC) 2.1.test.cc -o 2.1.test

2.1: 2.1.test 2.1.test.sh
	./2.1.test.sh

2.2.test: 2.2.h main_utils.h 2.2.test.cc
	$(GCC) 2.2.test.cc -o 2.2.test

2.2: 2.2.test 2.2.test.sh
	./2.2.test.sh

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

3.3: 3.3.test
	./3.3.test

3.4.test: 3.4.h main_utils.h 3.4.test.cc
	$(GCC) 3.4.test.cc -o 3.4.test

3.4: 3.4.test
	./3.4.test

4.1.test: 4.1.h main_utils.h 4.1.test.cc
	$(GCC) 4.1.test.cc -o 4.1.test

4.1: 4.1.test
	./4.1.test

4.2.test: 4.2.h main_utils.h 4.2.test.cc
	$(GCC) 4.2.test.cc -o 4.2.test

4.2: 4.2.test
	./4.2.test

4.3.test: 4.3.h main_utils.h 4.3.test.cc
	$(GCC) 4.3.test.cc -o 4.3.test

4.3: 4.3.test
	./4.3.test

4.4.test: 4.4.h main_utils.h 4.4.test.cc
	$(GCC) 4.4.test.cc -o 4.4.test

4.4: 4.4.test
	./4.4.test

4.5.test: 4.5.h main_utils.h 4.5.test.cc
	$(GCC) 4.5.test.cc -o 4.5.test

4.5: 4.5.test
	./4.5.test
