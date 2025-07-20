# 6502 Assembler
# Copyright (C) 2025
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC=gcc
INC_DIRS=include
IFLAGS=-I$(INC_DIRS)
CFLAGS=-Wall -Wextra -Wpedantic -std=c11 $(IFLAGS)
MAIN=main.c
SRC_DIR=src
EXE=asm6
OBJ_DIR=obj

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(MAIN) $^ -o $@

$(OBJS): $(SRCS)
	if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	if [ -f $(EXE) ]; then rm $(EXE); fi

.PHONY: all clean
