.PHONY: 3.1 3.2 3.3 3.4

CC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2

3.1: 3.1.o 3.1.test.cc
	$(CC) 3.1.o 3.1.test.cc -o 3.1
	@echo "3.1.test.cc compiled successfully! Running the program..."
	@./3.1 && echo "SUCCESS" || echo "FAILED"

3.1.o: 3.1.h 3.1.cc
	$(CC) -c 3.1.cc -o 3.1.o
	@echo "3.1.cc compiled successfully!"

3.2: 3.2.o 3.2.test0.cc 3.2.test1.cc 3.2.test2.cc
	$(CC) 3.2.o 3.2.test0.cc -o 3.2
	@echo "3.2.test0.cc compiled successfully! Running the program..."
	@(./3.2 && ($(CC) 3.2.o 3.2.test1.cc 2> /dev/null && echo "FAILED: Copy construction still allowed" || ($(CC) 3.2.o 3.2.test2.cc 2> /dev/null && echo "FAILED: Assignment still allowed" || echo "SUCCESS") ) ) || echo "FAILED"

3.2.o: 3.2.h 3.2.cc
	$(CC) -c 3.2.cc -o 3.2.o
	@echo "3.2.cc compiled successfully!"

3.3: 3.3.o 3.3.test.cc
	$(CC) 3.3.o 3.3.test.cc -o 3.3
	@echo "3.3.test.cc compiled successfully! Running the program..."
	@./3.3 && echo "SUCCESS" || echo "FAILED"

3.3.o: 3.3.h 3.3.cc
	$(CC) -c 3.3.cc -o 3.3.o
	@echo "3.3.cc compiled successfully!"

3.4: 3.4.o 3.4.test.cc
	$(CC) 3.4.o 3.4.test.cc -o 3.4
	@echo "3.4.test.cc compiled successfully! Running the program..."
	@./3.4 && echo "SUCCESS" || echo "FAILED"

3.4.o: 3.4.h 3.4.cc
	$(CC) -c 3.4.cc -o 3.4.o
	@echo "3.4.cc compiled successfully!"