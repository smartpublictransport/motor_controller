CFLAGS = -Wall
CC = g++
LIBPATH = /home/a7kntr/pod/lib/
vpath %.h include
SRC = src/main.cpp  src/motor_controller.cpp
LIB_SRC = lib/lib_motor_controller.cpp
LIB_OBJ = $(SRC:.cpp = .o)
OBJ = $(SRC:.cpp = .o)

Test: $(OBJ)
	$(CC) -L$(LIBPATH) $(CFLAGS) -lmotor_driver -o libTest $(OBJ) 
	$(CC) $(CFLAGS) -o test $(OBJ) 

clean:
	rm -f core *.o
