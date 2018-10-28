all: driver.o randf.o
	gcc driver.o randf.o
driver.o: driver.c randf.h
	gcc -c driver.c randf.h
randf.io: randf.c randf.h
	gcc -c randf.c
run:
	./a.out
clean:
	rm -f *.o *.out foo.txt *.gch *.~ 
