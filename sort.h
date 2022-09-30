//! @file sort.h

#ifndef   SORT_H
#define   SORT_H

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

//-----------------------------------------------------------------------------

void swap_lines      (void* first_pointer, void* second_pointer, size_t size_of_struct);

int compare_strings  (void *first_pointer, void *second_pointer);

void booble_sort     (void* string_array, int n_strings, int compare_strings (void* first_str, void* second_str));

//-----------------------------------------------------------------------------

#endif //SORT_H

