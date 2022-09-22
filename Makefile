all: onegin

onegin: onegin.o lines_handle.o input_output.o
	g++ onegin.o lines_handle.o input_output.o

onegin.o:  onegin.cpp
	g++ -c onegin.cpp

lines_handle.o: lines_handle.cpp
	     g++ -c lines_handle.cpp

input_output.o: input_output.cpp
	g++ -c input_output.cpp

clean:
	rm -rf *.o
