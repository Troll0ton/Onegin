//! @file input_output.h

#ifndef   INPUT_OUTPUT_H
#define   INPUT_OUTPUT_H

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

//-----------------------------------------------------------------------------

int num_of_strings    (char *file_buffer, int buffer_size);

int file_total_lenght (FILE *file);

int file_reader       (char *file_buffer, int buffer_size, FILE *file);

int file_printer      (struct Line *Text, int num_of_lines);

//-----------------------------------------------------------------------------

#endif //INPUT_OUTPUT_H
