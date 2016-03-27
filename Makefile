## *****************************************************************************
## File name : Makefile
## *****************************************************************************
## Function  : The file to manage all source files to generate execute file
## *****************************************************************************
## Author    : Gavin.Bai
## *****************************************************************************
## Time      : 2016.03.24
## *****************************************************************************
## Version   : (C) v1.0
## *****************************************************************************
## Modified  :
## *****************************************************************************

CC      = gcc
CCFLAGS = -O0 -Wall -g

RM      = rm
RMFLAGS = -rf

MK      = mkdir

OBJ_DIR = objs
EXE_DIR = exec
DIR     = $(OBJ_DIR) $(EXE_DIR)

EXE     = main
ASM     = $(EXE).asm
MAP     = $(EXE).map
SRC     = $(wildcard *.c)
OBJ     = $(patsubst %.c, %.o, $(SRC))

EXE    := $(addprefix $(EXE_DIR)/, $(EXE))
OBJ    := $(addprefix $(OBJ_DIR)/, $(OBJ))
##ASM    := $(addprefix $(EXE_DIR)/, $(ASM))
##MAP    := $(addprefix $(EXE_DIR)/, $(MAP))

.PHONY : all

all : $(DIR) $(EXE) $(ASM) ss

$(DIR) :
	$(MK) $@

$(EXE) : $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ -Map,Wl=$(MAP)
$(OBJ_DIR)/%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

$(ASM) : $(EXE)
	objdump $< -SD > $@

ss : $(EXE)
	size $<

run : $(EXE)
	./$<

clean :
	$(RM) $(RMFLAGS) $(DIR)
