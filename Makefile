CXX = g++
CXXFLAGS = -std=c++17 -Wall -pedantic-errors -g

SRCS =  main.cpp tree.cpp huffman.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = tree.h

MAIN = main

all: ${MAIN}
	@echo   main has been compiled

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.