//! @file input_output.h

#ifndef   INPUT_OUTPUT_H
#define   INPUT_OUTPUT_H

//-----------------------------------------------------------------------------

extern char *buf;

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

//-----------------------------------------------------------------------------

int num_of_strings (char *buf, int buf_size);

int size_of_file (FILE *file);

int file_reader (char *buf, int buf_size, FILE *file);

int file_printer (char *buf, int num, int *string_num);

//-----------------------------------------------------------------------------

#endif //INPUT_OUTPUT_H
