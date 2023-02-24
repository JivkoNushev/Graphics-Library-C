CXX = gcc
CXX_FLAGS = -Wall 

SOURCE_FILES = main.c pencil.c

main.o: main.c pencil.h
	${CXX} ${CXX_FLAGS} ${SOURCE_FILES} -o ./bin/testing.o