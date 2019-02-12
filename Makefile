executable.exe:main.o drawing.o reading.o
	gcc -o executable.exe main.o drawing.o reading.o 


main.o: main.c drawing.h reading.h
	gcc -c -o main.o main.c


drawing.o: drawing.c drawing.h reading.h
	gcc -c -o drawing.o drawing.c


reading.o: reading.c reading.h 
	gcc -c -o reading.o reading.c

