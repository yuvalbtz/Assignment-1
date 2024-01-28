CC=gcc
CFLAG= -Wall

all: mains maindloop maindrec loops recursives 

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

mains: main.o recursives
	$(CC) $(CFLAG) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(CFLAG) main.o ./libclassloops.so -lm -o maindloop

maindrec: main.o libclassrec.so
	$(CC) $(CFLAG) main.o ./libclassrec.so -lm -o maindrec

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a

libclassloops.so: basicClassification.c advancedClassificationLoop.c basicClassification.o advancedClassificationLoop.o
	$(CC) $(CFLAG) basicClassification.o advancedClassificationLoop.o -shared -o libclassloops.so

libclassrec.so: basicClassification.c advancedClassificationRecursion.c basicClassification.o advancedClassificationRecursion.o	
	$(CC) $(CFLAG)  basicClassification.o advancedClassificationRecursion.o -shared -o libclassrec.so

main.o: main.c
	$(CC) $(CFLAG) -c main.c

basicClassification.o: basicClassification.c
	$(CC) $(CFLAG) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c 
	$(CC) $(CFLAG) -fPIC -c basicClassification.c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c 
	$(CC) $(CFLAG) -fPIC -c basicClassification.c advancedClassificationRecursion.c

clean:
	rm *.so *.a *.o mains maindloop maindrec