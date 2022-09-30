//! @file lines_handle.h

#ifndef   LINES_HANDLE_H
#define   LINES_HANDLE_H

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

//-----------------------------------------------------------------------------

struct Line
{
    char *begin_line;

    int line_lenght;
};

//-----------------------------------------------------------------------------

int compare_strings (void *first_p, void *second_p);

int separate_lines  (char *buffer, int buffer_size, struct Line *Text);

void swap_lines     (void* first_pointer, void* second_pointer, size_t size_of_struct);

void bubble_sort    (void* string_array, int n_strings, int compare_strings (void* first_str, void* second_str));

//-----------------------------------------------------------------------------

#endif //LINES_HANDLE_H
