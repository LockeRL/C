#compiler
CC := gcc
FLAGS := -std=gnu99 -Wall -Werror -O2 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla

AR := ar rc
RAN := ranlib

#dirs
INC_DIR := ./inc
OBJ_DIR := ./out
C_FILES_DIR := ./src

#src, inc
C_MAIN = $(C_FILES_DIR)/main.c
C_FILES := $(wildcard $(C_FILES_DIR)/*.c)
INC_FILES := $(wildcard $(INC_DIR)/*.h)

#obj
OBJ_INC := $(C_FILES:$(C_FILES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_LIB_INC := $(filter-out $(OBJ_DIR)/main.o, $(OBJ_INC))

#libraries
STAT_LIB_INC := $(OBJ_LIB_INC:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.a)
DYN_LIB_INC := $(OBJ_LIB_INC:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.so)

#exe
APP := app.exe
SO_APP := app.out

.PHONY : clean static dynamic_load dynamic_layout

#create app.exe
$(APP): $(OBJ_INC)
	$(CC) $^ -o $@ -lm

$(OBJ_DIR):
	@mkdir -p $@

#create .o
$(OBJ_DIR)/%.o : $(C_FILES_DIR)/%.c $(INC_FILES) $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@


clean :
	rm -rf $(OBJ_DIR) *.exe *.txt *.out

static:
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c ./src/array.c -o ./out/array.o
	$(AR) ./out/array.a ./out/array.o
	$(RAN) ./out/array.a
	$(CC) $(FLAGS) ./src/main.c ./out/array.a -o ./app.exe

dynamic_load:
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -fPIC -c ./src/array.c -o ./out/array.o
	$(CC) -o ./out/array.so -shared ./out/array.o
	$(CC) $(FLAGS) -c ./src/main.c -o ./out/main.o
	$(CC) -o ./app.out ./out/main.o ./out/array.so -ldl

dynamic_layout:
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -fPIC -c ./src/array.c -o ./out/array.o
	$(CC) -o ./out/array.so -shared ./out/array.o
	$(CC) $(FLAGS) -c ./src/main.c -o ./out/main.o
	$(CC) -o ./app.out ./out/main.o ./out/array.so
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.