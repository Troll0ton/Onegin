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

struct File_buffer
{
    char *file_data;

    int   file_size;

    int   num_of_lines;
};

//-----------------------------------------------------------------------------

void file_handle    (struct File_buffer *File_input, FILE *file);

int  num_of_strings (struct File_buffer *File_input);

int  file_reader    (struct File_buffer *File_input, FILE *file);

int  file_size      (FILE *file);

int  file_printer   (struct Line *Text, int num_of_lines);

//-----------------------------------------------------------------------------

#endif //INPUT_OUTPUT_H
