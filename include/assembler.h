/* 6502 Assembler
 * Copyright (C) 2025
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

/* Local headers */
#include "common.h"

/**
 * @brief The main assembler function
 *
 * @description This function takes in the .asm
 * file and assembles the assembly code to executable.
 *
 * @param[in] filename The assembly code file.
 *
 * @returns The result of assembling.
 */
Result assemble(const char * const filename);

#endif /* ASSEMBLER_H */
