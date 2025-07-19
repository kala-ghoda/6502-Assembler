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

/**
 * @file common.h Common definitions header file
 *
 * @description Common structure and constant definitions
 * to be used throughout the program.
 */

#ifndef COMMON_H
#define COMMON_H

#include <string.h>

/* Minimum file name size */
#define MIN_FILENAME_SIZE		5U

/* Maximum file name size */
#define MAX_FILENAME_SIZE		64U

/* Maximum error message length, including NULL termination */
#define MAX_ERROR_MSG_LENGTH	128U

/**
 * @brief Enumeration for result values
 */
typedef enum {
	/* Result code for success */
	RESULT_OK = 0,
	/* Result code for missing arguments */
	RESULT_MISSING_ARG,
	/* Result code for invalid paramters */
	RESULT_INVALID_PARAM,
	/* Result code for failed to allocate memory */
	RESULT_FAILED_TO_ALLOCATE_MEMORY,
	/* Result code for invalid filename */
	RESULT_INVALID_FILE_EXTENSION,
	/* Result code for unknown error */
	RESULT_ERROR,
} ResultCode;

/**
 * @brief Result structure.
 *
 * @description A structure to return the result
 * of running a function/routine.
 */
typedef struct result_t {
	/* Result error code */
	ResultCode code;
	/* Error message */
	char errStr[MAX_ERROR_MSG_LENGTH];
} Result;

/**
 * @brief Function to find minimum of two
 *
 * @param[in] a First value
 * @param[in] b Second value
 *
 * @returns Minimum value of the two
 */
static inline size_t min(size_t a, size_t b) {
	return a < b ? a : b;
}

/**
 * @brief Wrapper for strncpy
 *
 * @param[in] dst Destination string
 * @param[in] errorString Error String to be copied
 */
static inline void
copyMessage(char * const dst,
			const char * const errorString) {
	size_t len = strlen(errorString);
	size_t last_index = min(len, MAX_ERROR_MSG_LENGTH - 1U);

	strncpy(dst, errorString, MAX_ERROR_MSG_LENGTH - 2U);
	dst[last_index] = '\0';
}

#endif /* COMMON_H */
