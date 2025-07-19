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

/* C standard libraries */
#include <stdio.h>
#include <string.h>

/* Local headers */
#include "assembler.h"

/* Extension string size */
#define EXTENSION_SIZE		4U

/* The file extension */
static const char * const extension = ".asm";

Result assemble(const char * const filename) {
	Result result;
	result.code = RESULT_OK;
	result.errStr[0] = '\0';

	size_t len = strlen(filename);
	size_t index = len - EXTENSION_SIZE;
	int ret = strncmp(filename + index, extension, EXTENSION_SIZE);
	if (ret != 0) {
		result.code = RESULT_INVALID_FILE_EXTENSION;
		copyMessage(result.errStr, "Invalid file name passed: wrong extension");
		return result;
	}

	printf("Filename Printed : %s", filename);
	return result;
}
