CXX = gcc
CXX_FLAGS = -Wall 

EXECS = main.o

main.o: main.c
	${CXX} ${CXX_FLAGS} main.c -o a.o