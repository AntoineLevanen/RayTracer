output: main.o renderer.o
	g++ -std=c++0x -Wall main.o renderer.o -o ray-tracer.exe -lsfml-graphics -lsfml-window -lsfml-system

main: main.cpp
	g++ -c main.cpp

renderengine: renderer.cpp renderer.hpp
	g++ -c renderer.cpp
