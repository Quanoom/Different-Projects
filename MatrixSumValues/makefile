all : executable.exe

output.o : matrixSumElements.c
	gcc -c -o output.o matrixSumElements.c

executable.exe : output.o
	gcc -o executable.exe output.o