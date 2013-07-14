#
# Author: Sandeep Singh
# Date  : July 13, 2013
#
# Copyright 2013 Sandeep Singh (sandeepsinghmails@gmail.com)
#
# This file is part of InputArgsTracingLib.
# InputArgsTracingLib is free software: you can redistribute it
# and/or modify it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# InputArgsTracingLib is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with InputArgsTracingLib. If not, see <http://www.gnu.org/licenses/>.
# 
#/

# Source Code 
SRC = $(SRC_DIR)/InputArgsTracingLib.c

# Object Files
OBJ = InputArgsTracingLib.o
# Target Static Library
TARGET = libInputArgsTracing.a

# Source Directory
SRC_DIR = $(PWD)
# Object Directory
OBJ_DIR = $(PWD)/obj
# Output Directory
TARGET_DIR = $(PWD)/lib

# Command To Create Directory
MKDIR_P = mkdir -p
# Command To Move Object Files To Object Directory
MV = $(shell mv $(OBJ) $(OBJ_DIR)/$(OBJ))

all: directories memlib

directories: $(OBJ_DIR) ${TARGET_DIR}
memlib: $(TARGET)

# Create Object Directory
${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}
# Create Output Directory
${TARGET_DIR}:
	${MKDIR_P} ${TARGET_DIR}

# Compiler Flags 
CFLAGS = -g -ansi -Wall -pedantic
# Compiler
CC = gcc 

# Create Object Files
OBJ: $(SRC)
	$(CC) $(CFLAGS) $(SRC) $< -o $@

# Create Target Library
$(TARGET): $(OBJ)
	$(MV)
	ar rc $(TARGET_DIR)/$(TARGET) $(OBJ_DIR)/$(OBJ)

# Clean the Object Files and Library
clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)
	rm -rf gdbcmds
	rm -rf InputArgsTracingLogs.txt

 

