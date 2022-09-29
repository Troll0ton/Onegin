all: square

square: main.o lines_handle.o input_output.o
	g++ main.o lines_handle.o input_output.o

main.o: main.cpp
	g++ -c main.cpp

lines_handle.o: lines_handle.cpp
	g++ -c lines_handle.cpp

input_output.o: input_output.cpp
	g++ -c input_output.cpp

clean:
	rm -rf *.o
