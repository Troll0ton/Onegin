#include "lines_handle.h"

//-----------------------------------------------------------------------------

int compare_strings (void *first_p, void *second_p)
{
    struct Line *first_line  = (struct Line*) first_p;
    struct Line *second_line = (struct Line*) second_p;

    return strcmp (first_line->begin_line, second_line->begin_line);
}

//-----------------------------------------------------------------------------

int separate_lines (char *buffer, int buffer_size, struct Line *Line_p)
{
    int num_line = 0;

    int cur_len = 0;

    for(int i = 0; i < buffer_size; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';

            Line_p[num_line].begin_line = buffer + i - cur_len;

            cur_len = 0;
            num_line++;
        }

        else
        {
            cur_len++;
        }
    }

    Line_p[num_line].begin_line = (buffer + buffer_size - cur_len);

    num_line++;

    printf ("%d\n\n", num_line);

    return num_line;

}

//-----------------------------------------------------------------------------

void bubble_sort (void* string_array, int n_strings, int compare_strings (void* first_str, void* second_str))
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

void swap_lines (void* first_pointer, void* second_pointer, size_t size_of_struct)
{
    void* tmp = calloc (1, size_of_struct);

    memcpy (tmp , first_pointer, size_of_struct);
    memcpy (first_pointer, second_pointer, size_of_struct);
    memcpy (second_pointer, tmp, size_of_struct);
}

//-----------------------------------------------------------------------------

