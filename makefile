OBJ = screen.o testmain.o appdevWav.o
APPNAME = testmain.a

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm -lcurl

%.o : %.c
	gcc -c -o $@ $< -std=c99

clean:
	rm $(APPNAME) $(OBJ)
due:
	tar -cvf sound_detection.tar *.c *.h makefile README.txt
