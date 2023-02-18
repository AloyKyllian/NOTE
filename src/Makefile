test : note.o moyenne.o tst.o affichage.o
	gcc -o test.out note.o moyenne.o tst.o affichage.o

note.o : note.c note.h
	gcc -c note.c

moyenne.o : moyenne.c moyenne.h
	gcc -c moyenne.c

affichage.o : affichage.c affichage.h
	gcc -c affichage.c

tst.o : tst.c
	gcc -c tst.c


clean : 
	rm -rf *.o