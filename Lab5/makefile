compileAll : compMS.o runMS.o compRecMS.o runRecMS.o filesort.o
	gcc compMS.o runMS.o compRecMS.o runRecMS.o filesort.o -o run

compMS.o : MS.h compMS.c
	gcc -c compMS.c 

compRecMS.o : MS.h compRecMS.c
	gcc -c compRecMS.c 

runMS.o : MS.h runMS.c
	gcc -c runMS.c

runRecMS.o : MS.h runRecMS.c
	gcc -c runRecMS.c 

filesort.o : MS.h filesort.c
	gcc -c filesort.c
