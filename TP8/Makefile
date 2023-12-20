SHELL=bash
GCC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2 

.PHONY: 1.1 1.2 1.3.1 1.3.2 1.3.3 1.4 1.5 1.6 1.7

clean:
	rm -f *.o 1.1 1.2 1.3 1.3.1 1.3.2 1.3.3 1.4 1.5 1.7 1.5.out

1.1: 1.1.o 1.1.test.cc main_utils.h
	$(GCC) 1.1.o 1.1.test.cc -o 1.1
	@echo "1.1.test.cc compiled successfully! Running the program..."
	bash -c "ulimit -S -v 1000000; ./1.1 && echo "SUCCESS" || (echo "FAILED"; exit 1); exit"

1.1.o: 1.1.h 1.1.cc
	$(GCC) -c 1.1.cc -o 1.1.o
	@echo "1.1.cc compiled successfully!"

1.2: 1.2.o 1.2.test.cc main_utils.h
	$(GCC) 1.2.o 1.2.test.cc -o 1.2
	@echo "1.2.test.cc compiled successfully! Running the program..."
	./1.2 && echo "SUCCESS" || (echo "FAILED"; exit 1)

1.2.o: 1.2.h 1.2.cc
	$(GCC) -c 1.2.cc -o 1.2.o
	@echo "1.2.cc compiled successfully!"

1.3.1: 1.3.o 1.3.1.test.cc main_utils.h
	$(GCC) 1.3.o 1.3.1.test.cc -o 1.3.1
	@echo "1.3.1.test.cc compiled successfully! Running the program..."
	./1.3.1 && echo "SUCCESS" || (echo "FAILED"; exit 1)

1.3.2: 1.3.o 1.3.2.test.cc main_utils.h
	$(GCC) 1.3.o 1.3.2.test.cc -o 1.3.2
	@echo "1.3.2.test.cc compiled successfully! Running the program..."
	./1.3.2 && echo "SUCCESS" || (echo "FAILED"; exit 1)

1.3.3: 1.3.o 1.3.3.test.cc main_utils.h
	$(GCC) 1.3.o 1.3.3.test.cc -o 1.3.3
	@echo "1.3.3.test.cc compiled successfully! Running the program..."
	./1.3.3 && echo "SUCCESS" || (echo "FAILED"; exit 1)

1.3.o: 1.3.h 1.3.cc
	$(GCC) -c 1.3.cc -o 1.3.o
	@echo "1.3.cc compiled successfully!"

1.4: 1.4.o 1.4.test.cc main_utils.h
	$(GCC) 1.4.o 1.4.test.cc -o 1.4
	@echo "1.4.test.cc compiled successfully! Running the program..."
	./1.4 && echo "SUCCESS" || (echo "FAILED"; exit 1)

1.4.o: 1.4.h 1.4.cc
	$(GCC) -c 1.4.cc -o 1.4.o
	@echo "1.4.cc compiled successfully!"

matrix_ops.o: matrix_ops.h matrix_ops.cc
	$(GCC) -c matrix_ops.cc -o matrix_ops.o
	@echo "matrix_ops.cc compiled successfully!"

1.5: 1.4.o matrix_ops.o 1.5.test.cc
	$(GCC) 1.4.o matrix_ops.o 1.5.test.cc -o 1.5
	@echo "1.5.test.cc compiled successfully! Running the program..."
	./1.5 > 1.5.out
	@echo "Comparing 1.5.out to the expected output: 1.5.expected"
	@diff 1.5.out 1.5.expected || (echo "The output is not as expected! See the diff above."; exit 1)
	@echo "SUCCESS"

1.7: 1.4.o matrix_ops.o 1.7.test.cc
	$(GCC) 1.4.o matrix_ops.o 1.7.test.cc -o 1.7
	@echo "1.7.test.cc compiled successfully! Running the program..."
	./1.7
