#
# Makefile for dictionary
#

CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -g

shortestpath: dictionary.cpp main.cpp
	${CXX} ${FLAGS} -o shortestpath main.cpp dictionary.cpp

clean:
	rm -f shortestpath