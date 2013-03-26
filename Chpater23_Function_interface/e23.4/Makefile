main: main.o para_allocator.o
	gcc -g main.o para_allocator.o -o main

main.o: main.c para_allocator.h
	gcc -c main.c

para_allocator.o:
	gcc -c para_allocator.c

clean:
	@echo "cleaning project"
	-rm main *.o

.PHONY: clean
