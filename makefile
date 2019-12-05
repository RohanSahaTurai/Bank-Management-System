CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

OBJ = Main.c LinkedList.c Login.c User.c Admin.c AddUser.c Validate.c Encrypt.c Log.c

rebuild : clean build

build : $(OBJ)
	$(CC) $(CFLAGS) -o Bank $(OBJ) 

clean :	
	rm -f *.out *.o

debug: clean $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG -o Bank $(OBJ)