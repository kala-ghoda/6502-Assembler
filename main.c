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

#include <stdio.h>

static const char * const usage =
"6502 Microprocessor Assembler:\n"
"Usage:\n"
"./asm6 -f <assembly_file_name>\n\n"
"Args:\n"
"  -f 	--file <file_name>	Sets the filename argument.\n";

static void printUsage() {
	printf("%s", usage);
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printUsage();
	}

	return 0;
}
