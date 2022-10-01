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

#define DATA_TEXT_FILE "hamlet.txt"
#define OUT_FILE "hamlet1.txt"

//-----------------------------------------------------------------------------

struct Option
{
    char *opt_name;

    int (*func)(void *first_p, void *second_p);
};

//-----------------------------------------------------------------------------

struct File_buffer
{
    char *file_data;

    int   file_size;

    int   num_of_lines;
};

//-----------------------------------------------------------------------------

void arg_handle     (int argc, char* argv[], const struct Option cmd[], int options_range,
                     void* string_array,     int num_of_lines);

void file_handle    (struct File_buffer *File_input, FILE *file);

int  num_of_strings (struct File_buffer *File_input);

int  file_reader    (struct File_buffer *File_input, FILE *file);

int  file_size      (FILE *file);

int  file_printer   (struct Line *Text, int num_of_lines);

//-----------------------------------------------------------------------------

#endif //INPUT_OUTPUT_H
