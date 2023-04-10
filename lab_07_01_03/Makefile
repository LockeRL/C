#compiler
CC := gcc
FLAGS := -std=c99 -Wall -Werror -O2 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
UNIT_FLAGS := $(FLAGS) -lcheck 

#dirs
INC_DIR := ./inc
OBJ_DIR := ./out
C_FILES_DIR := ./src
UNIT_DIR := ./unit_tests

#src, inc
C_FILES := $(wildcard $(C_FILES_DIR)/*.c)
UNIT_FILES := $(wildcard $(UNIT_DIR)/*.c)
INC_FILES := $(wildcard $(INC_DIR)/*.h)

#obj
OBJ_INC := $(C_FILES:$(C_FILES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_UNIT := $(UNIT_FILES:$(UNIT_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_UNIT += $(filter-out $(OBJ_DIR)/main.o, $(OBJ_INC))

#exe
APP := app.exe
UNIT := unit_tests.exe

.PHONY : clean unit func_tests run

$(OBJ_DIR):
	@mkdir -p $@

#create .o programm
$(OBJ_DIR)/%.o : $(C_FILES_DIR)/%.c $(INC_FILES) $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

#create .o units	
$(OBJ_DIR)/%.o : $(UNIT_DIR)/%.c $(INC_FILES) $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

#create main.exe
$(APP): $(OBJ_INC)
	$(CC) $^ -o $@

#create unit.exe
$(UNIT): $(OBJ_UNIT)
	$(CC) $(OBJ_UNIT) -o $@ $(UNIT_FLAGS) -lm

unit : $(UNIT)
	@./$(UNIT)

run : $(APP)
	@./$(APP)

clean :
	rm -rf $(OBJ_DIR) *.exe *.txt

func_tests :
	cd ./func_tests/scripts && ./func_tests.sh
