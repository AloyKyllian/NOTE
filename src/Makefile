test : note.o moyenne.o tst.o
	gcc -fno-stack-protector -o test.out note.o moyenne.o tst.o

note.o : note.c note.h
	gcc -fno-stack-protector -c note.c

moyenne.o : moyenne.c moyenne.h
	gcc -fno-stack-protector -c moyenne.c

tst.o : tst.c
	gcc -fno-stack-protector -c tst.c

clean : 
	rm -rf *.o