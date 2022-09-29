#include "lines_handle.h"

//-----------------------------------------------------------------------------

int compare_strings (const void *first_p, const void *second_p)
{
    struct Line *first_line  = (struct Line*) first_p;
    struct Line *second_line = (struct Line*) second_p;

    return strcmp (first_line->Pbegin_line, second_line->Pbegin_line);
}

//-----------------------------------------------------------------------------

int separate_lines (char *buffer, int buffer_size, struct Line *Line_p)
{
    int num_line = 0;

    char *line_begin = buffer;

    int cur_len = 0;

    for(int i = 0; i < buffer_size; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';

            Line_p[num_line].Pbegin_line = buffer + i - cur_len;
            // ??

            cur_len = 0;
            num_line++;
        }

        else
        {
            cur_len++;
        }
    }


    // ??

    (Line_p + num_line) -> Pbegin_line = (buffer + buffer_size - cur_len);

    num_line++;

    printf ("%d\n\n", num_line);

    return num_line;

}

//-----------------------------------------------------------------------------
