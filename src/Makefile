note : note.o 
	gcc -fno-stack-protector -o note.out note.o 

note.o : note.c note.h
	gcc -fno-stack-protector -c note.c


clean : 
	rm -rf *.o