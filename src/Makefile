test : note.o moyenne.o tst.o affichage.o
	gcc -fno-stack-protector -o test.exe note.o moyenne.o tst.o affichage.o

note.o : note.c note.h
	gcc -fno-stack-protector -c note.c

moyenne.o : moyenne.c moyenne.h
	gcc -fno-stack-protector -c moyenne.c

affichage.o : affichage.c affichage.h
	gcc -fno-stack-protector -c affichage.c

tst.o : tst.c
	gcc -fno-stack-protector -c tst.c


clean : 
	rm -rf *.o