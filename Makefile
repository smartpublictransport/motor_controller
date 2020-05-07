CFLAGS = -Wall
CC = g++
LIBPATH = /home/a7kntr/pod/lib/
INC = include
vpath %.h include/
SRC = src/main.cpp  src/motor_controller.cpp
LIB_SRC = lib/lib_motor_controller.cpp
LIB_OBJ = $(LIB_SRC:.cpp = .o)
OBJ = $(SRC:.cpp = .o)

test: $(OBJ)
	$(CC) -L$(LIBPATH) $(CFLAGS) -lTest -lmotor_driver -o test $(OBJ) 

lib: $(LIB_OBJ) 
	$(CC) -I$(INC) $(CFLAGS) -fPIC -shared -o libTest.so $(LIB_OBJ) 

clean:
	rm -f core *.o
