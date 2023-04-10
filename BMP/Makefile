#compiler
CC := gcc
FLAGS := -std=gnu99 -Wall -O2 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
PY := python3

#dirs
OBJ_DIR := ./out
LIB_DIR := ./lib

#obj
OBJ_FILE := $(OBJ_DIR)/bmp.o

#c
C_FILE := ./src/bmp.c

#lib
LIB_SO := ./lib/bmp.so

#py
PY_APP := ./py/main.py

.PHONY : clean run

#create lib
$(LIB_SO): $(OBJ_DIR) $(LIB_DIR)
	$(CC) $(FLAGS) -fPIC -c $(C_FILE) -o $(OBJ_FILE)
	$(CC) -o $(LIB_SO) -shared $(OBJ_FILE)

$(OBJ_DIR):
	@mkdir -p $@

$(LIB_DIR):
	@mkdir -p $@


clean :
	rm -rf $(OBJ_DIR) .idea $(LIB_DIR) *.exe *.txt *.out ./py/__pycache__

run : $(LIB_SO)
	$(PY) $(PY_APP)