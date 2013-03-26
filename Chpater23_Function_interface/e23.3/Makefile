main: main.o redirect_ptr.o
	gcc main.o redirect_ptr.o -o main

main.o: main.c redirect_ptr.h
	gcc -c main.c

redirect_ptr.o: redirect_ptr.c redirect_ptr.h
	gcc -c redirect_ptr.c

clean:
	@echo "cleanning project"
	-rm main *.o

.PHONY:
	clean
	
