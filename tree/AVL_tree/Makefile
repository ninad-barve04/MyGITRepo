avltree: main.o avl.o avl_utilities.o avl_rotations.o
	gcc -o avltree main.o avl.o avl_utilities.o avl_rotations.o

avltree_debug:
	# avl.c main.c avl_utilities.c avl_rotations.c
	gcc -g *.c -o avltree_debug

clean:
	-rm a.out
	-rm avltree
	-rm *.o
	-rm avltree_debug
