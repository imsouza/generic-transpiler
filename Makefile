# Nome do projeto
PROJECT = generic

# Definição dos diretórios dinâmicos
DIR_OUT = obj
DIR_SRC += .
DIR_SRC = ./src
DIR_INC += $(addprefix -I, $(DIR_SRC))

C_SOURCE += $(wildcard $(addsuffix /*.cpp, $(DIR_SRC)))
OBJ := $(patsubst %.cpp, %.o, $(C_SOURCE))

# Definição do compilador
CC = g++

# Arquivo executável
EXE := obj/$(PROJECT)
 
# Definição das flags de compilação
CC_FLAGS = 	-c	  	\
            -std=c++17	\

# Comandos para limpeza recursiva dos arquivos 
# remanescentes na pasta src/		 
RM = rm -rf
MD = $(shell mkdir -p $(DIR_OUT))

# Linkagem e Compilação
.PHONY:all

all:$(OBJ) $(EXE)
%.o: %.cpp
	$(MD)
	$(CC) $(DIR_INC) $(CC_FLAGS) $< -o $@

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(DIR_INC)

	$(RM) $(DIR_SRC)/*.o

# Limpa os arquivos objetos
clean:
	cd obj && $(RM) $(PROJECT)

# Executa o programa
run: $(EXE)
	cd obj && ./${PROJECT}