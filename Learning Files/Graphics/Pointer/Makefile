all: compile link execute

compile:
	g++ -IC:\Libraries\SFML-3.0.0\include -c main.cpp

link:

	g++ main.o -o main -LC:\Libraries\SFML-3.0.0\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

execute:
	set PATH=C:\Libraries\SFML-3.0.0\bin;%PATH% && main.exe
