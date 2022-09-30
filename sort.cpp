#include "sort.h"

//-----------------------------------------------------------------------------

void swap_lines (void* first_pointer, void* second_pointer, size_t size_of_struct)
{
    void* tmp = calloc (size_of_struct, 1);

    memcpy (tmp , first_pointer, size_of_struct);
    memcpy (first_pointer, first_pointer, size_of_struct);
    memcpy (second_pointer, tmp, size_of_struct);
}

//-----------------------------------------------------------------------------

int compare_strings (void *first_pointer, void *second_pointer)
{
    struct Line *first_line  = (struct Line*) first_pointer;
    struct Line *second_line = (struct Line*) second_pointer;

    return strcmp (first_line->begin_line, second_line->begin_line);
}

//-----------------------------------------------------------------------------

void booble_sort (void* string_array, int n_strings, int compare_strings (void* first_str, void* second_str))
{
    for(int i = 0; i < n_strings; i++)
    {
        for(int j = i + 1; j < n_strings; j++)
        {
            if(compare_strings ((struct Line*) string_array + i, (struct Line*) string_array + j) > 0)
            {
                swap_lines ((struct Line*) string_array + i, (struct Line*) string_array + j, sizeof (struct Line));
            }
        }
    }
}

//-----------------------------------------------------------------------------


