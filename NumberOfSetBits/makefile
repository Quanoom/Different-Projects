all : executable.exe

output.o : source.c
	gcc -c -o output.o source.c

executable.exe : output.o
	gcc -o executable.exe output.o