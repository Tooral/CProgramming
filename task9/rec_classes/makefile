rec_classes: rec_classes.o request.o readline.o
	gcc -o rec_classes request.o readline.o rec_classes.o
rec_classes.o: rec_classes.c request.h readline.h
	gcc -c rec_classes.c
request.o: request.c request.h readline.h
	gcc -c request.c
readline.o: readline.c readline.h
	gcc -c readline.c

