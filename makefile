# text file
cc = gcc
object = mian.o
main : $(object)
	$(cc) -o main $(object)
main.o : main.c main.h
	$(cc) -c main.c
clear:
	rm -i $(object)
