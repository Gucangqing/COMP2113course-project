function.o: function.cpp function.h
	g++ -c function.cpp
mainbody.o: mainbody.cpp function.h
	g++ -c mainbody.cpp
main:	function.o mainbody.o
	g++ -pedantic-errors -std=c++11 function.o mainbody.o -o main
