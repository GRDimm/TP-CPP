CC=g++ -std=c++11 -Wall -Wextra -Werror -Wno-sign-compare -O2

main: main.cc student.o class.o io.o
	$(CC) student.o class.o io.o main.cc -o main

student.o: student.h student.cc
	$(CC) -c -o student.o student.cc

class.o: student.h class.h class.cc
	$(CC) -c -o class.o class.cc

io.o: student.h class.h io.h io.cc
	$(CC) -c -o io.o io.cc