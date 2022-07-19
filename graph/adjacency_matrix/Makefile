graph: main.o adjacency_matrix.o queue.o astack.o algorithms.o
	gcc -o graph main.o adjacency_matrix.o queue.o astack.o algorithms.o

clean: 
	-rm *.o
	-rm graph
	-rm a.out
	-rm debugger

debugger:
	gcc -g *.c -o debugger