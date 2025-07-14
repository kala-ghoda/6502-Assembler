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

/* C Standard library headers */
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/* Local headers */
#include "common.h"

/**
 * @brief Structure to hold the parsed values
 *
 */
typedef struct parsed_val_t {
	/* Flag to check if it is help command */
	bool isHelpCommand;
	/* Flag to check if it is version command */
	bool isVersionCommand;
	/* Flag to check if file is given */
	bool isFileGiven;
	/* File name */
	char * filename;
} ParsedValues_t;

/* Version string */
static const char * const version_str = "v1.0.0";

/* Usage string */
static const char * const usage =
"6502 Microprocessor Assembler:\n"
"Usage:\n"
"./asm6 -f <assembly_file_name>\n\n"
"Args:\n"
"  -f 	--file <file_name>	Sets the filename argument.\n"
"  -h 	--help				Prints the tool overview.\n"
"  -V 	--version			Prints the tool version info.\n";

static void printVersion() {
	printf("%s", version_str);
}

static void printUsage() {
	printf("%s", usage);
}

static Result fileCheck(const char * const filename) {
	Result result = { .code = RESULT_OK };
	result.errStr[0] = '\0';

	if ((strlen(filename) <  MIN_FILENAME_SIZE) ||
		(strlen(filename) >= MAX_FILENAME_SIZE)) {
		result.code = RESULT_INVALID_PARAM;
		copyMessage(result.errStr,
			  		"Error: Filename size out of bounds");
	}

	return result;
}

static Result parseArgs(int argc, char *argv[],
						ParsedValues_t * pv_ptr) {

	Result result = {.code = RESULT_OK };
	result.errStr[0] = '\0';

	if (NULL == argv) {
		result.code = RESULT_INVALID_PARAM;
		copyMessage(result.errStr,
			  		"Error: Invalid parameter");
		return result;
	}

	const char * short_options = "hVf:";
	const struct option long_options[] = {
		{.name = "help", .has_arg = no_argument, .flag = NULL },
		{.name = "version", .has_arg = no_argument, .flag = NULL },
		{.name = "filename", .has_arg = required_argument, .flag = NULL },
	};
	int longindex = 0;

	while (true) {
		int opt_ret = getopt_long(argc, argv, short_options,
								  long_options, &longindex);
		if (opt_ret == -1) {
			break;
		}

		switch (opt_ret) {
			case 'h':
				printUsage();
				result.code = RESULT_OK;
				result.errStr[0] = '\0';
				pv_ptr->isHelpCommand = true;
				return result;
			case 'V':
				printVersion();
				result.code = RESULT_OK;
				result.errStr[0] = '\0';
				pv_ptr->isVersionCommand = true;
				return result;
			case 'f':
				result.code = RESULT_OK;
				result.errStr[0] = '\0';
				pv_ptr->isFileGiven = true;
				result = fileCheck(optarg);
				if (result.code != RESULT_OK) {
					return result;
				}

				size_t filenameSize = strlen(optarg);
				pv_ptr->filename = (char *)malloc(filenameSize + 1U);
				if (NULL == pv_ptr->filename) {
					result.code = RESULT_FAILED_TO_ALLOCATE_MEMORY;
					copyMessage(result.errStr, "Failed to allocate memory for filename");
					return result;
				}

				strncpy(pv_ptr->filename, optarg, filenameSize);
				pv_ptr->filename[filenameSize] = '\0';
				break;
			case '?':
			default:
				break;
		}
	}

	return result;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printUsage();
	}

	Result result;
	result.code = RESULT_OK;
	result.errStr[0] = '\0';

	ParsedValues_t pv = { .isFileGiven = false, .filename = NULL };
	result = parseArgs(argc, argv, &pv);
	if (RESULT_OK != result.code) {
		fprintf(stderr, "Failed to parse argument: %s", result.errStr);
		return EXIT_FAILURE;
	}
	if (pv.isHelpCommand || pv.isVersionCommand) {
		return EXIT_SUCCESS;
	}
	if (!pv.isFileGiven) {
		fprintf(stderr, "Error: File not provided\n");
		return EXIT_FAILURE;
	}

	printf("Filename : %s\n", pv.filename);
	free(pv.filename);
	pv.filename = NULL;

	return EXIT_SUCCESS;
}
