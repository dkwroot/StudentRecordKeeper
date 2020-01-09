all: main.o student.o
	g++ -std=c++11 main.o student.o -o output

main.o: main.cpp main.h student.h
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

clean:
	rm *.o