PROJECT = generic

DIR_OUT = obj
DIR_SRC += .
DIR_SRC = ./src
DIR_INC += $(addprefix -I, $(DIR_SRC))

C_SOURCE += $(wildcard $(addsuffix /*.cpp, $(DIR_SRC)))
OBJ := $(patsubst %.cpp, %.o, $(C_SOURCE))

CC = g++

EXE := obj/$(PROJECT)
 
CC_FLAGS = 	-c	  	\
			-O3		\
            -std=c++17	\

RM = rm -rf
MD = $(shell mkdir -p $(DIR_OUT))

.PHONY:all

all:$(OBJ) $(EXE)
%.o: %.cpp
	$(MD)
	$(CC) $(DIR_INC) $(CC_FLAGS) $< -o $@

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(DIR_INC)

	$(RM) $(DIR_SRC)/*.o

clean:
	cd obj && $(RM) $(PROJECT)

run: $(EXE)
	cd obj && ./${PROJECT} < ../input/test_file_02.g