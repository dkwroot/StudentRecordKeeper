all: main.o student.o helpers.o
	g++ -std=c++11 main.o student.o helpers.o -o output

main.o: main.cpp main.h student.h helpers.h
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

helpers.o: helpers.cpp helpers.h student.h
	g++ -c helpers.cpp

clean:
	rm *.o