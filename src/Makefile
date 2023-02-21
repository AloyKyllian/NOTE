test : note.o moyenne.o tst.o affichage.o
	gcc -o test.out note.o moyenne.o tst.o affichage.o -DLINUX

note.o : note.c note.h
	gcc -c note.c -DLINUX

moyenne.o : moyenne.c moyenne.h
	gcc -c moyenne.c -DLINUX

affichage.o : affichage.c affichage.h
	gcc -c affichage.c -DLINUX

tst.o : tst.c
	gcc -c tst.c -DLINUX

test_W: note.c moyenne.c tst.c affichage.c affichage.h moyenne.h note.h
gcc -c note.c -DWINDOWS
gcc -c moyenne.c -DWINDOWS
gcc -c tst.c -DWINDOWS
gcc -c affichage.c -DWINDOWS
gcc -o test.exe note.o moyenne.o tst.o affichage.o -DWINDOWS
clean : 
	rm -rf *.o