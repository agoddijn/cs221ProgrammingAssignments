all : huftree

huftree : huftree.o codeTree.o myQueue.o
	g++ huftree.o codeTree.o myQueue.o -o huftree

huftree.o : huftree.cc codeTree.h
	g++ -Wall -c huftree.cc -o huftree.o

codeTree.o : codeTree.cc codeTree.h node.h
	g++ -Wall -c codeTree.cc -o codeTree.o

myQueue.o : myQueue.cc myQueue.h node.h
	g++ -Wall -c myQueue.cc -o myQueue.o

clean :
	rm *.o
	rm huftree