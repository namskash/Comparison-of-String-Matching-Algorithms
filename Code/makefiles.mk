exec.exe: driver.o server.o
	g++ driver.o server.o -o exec.exe

driver.o: driver.cpp HEADER.h
	g++ driver.cpp -c

server.o: server.cpp HEADER.h
	g++ server.cpp -c