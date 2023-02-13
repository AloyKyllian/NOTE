note : note.o moyenne.o affichage.o
	gcc -fno-stack-protector -o note.out note.o 

note.o : note.c note.h
	gcc -fno-stack-protector -c note.c

moyenne.o : moyenne.c moyenne.h
	gcc -o moyenne.c

affichage.o : affichage.c 
	gcc -o affichage.c

clean : 
	rm -rf *.o