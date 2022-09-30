#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

int main ()
{
    FILE   *file  = fopen ("hamlettest.txt", "rb");
    assert (file != NULL);

    int buffer_size = file_size (file) + 1;

    char *file_buffer = (char*) calloc (buffer_size, sizeof (char));

    file_reader (file_buffer, buffer_size, file);

    //-----------------------------------------------------------------------------

    int num_of_lines = num_of_strings (file_buffer, buffer_size);

    struct Line *Text = (struct Line*) calloc (num_of_lines, sizeof (struct Line));

    separate_lines (file_buffer, buffer_size, Text);

    //-----------------------------------------------------------------------------

    bubble_sort ((void*)Text, num_of_lines, &compare_strings);

    for(int i = 0; i < num_of_lines; i++)
    {
        printf ("%s\n", (Text + i) -> begin_line);
    }

    fclose (file);

    file_printer (Text, num_of_lines);

    return 0;
}

//-----------------------------------------------------------------------------
