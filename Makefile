CFLAGS = -Wall
CC = g++
LIBPATH = /home/a7kntr/pod/lib
vpath %.h include
SRC = src/main.cpp  src/motor_controller.cpp
OBJ = $(SRC:.cpp = .o)

Test: $(OBJ)
	$(CC) -L$(LIBPATH) $(CFLAGS) -lmotor_driver -o test $(OBJ) 
clean:
	rm -f core *.o
