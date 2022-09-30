#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

int main ()
{
    struct File_buffer *File_input = (struct File_buffer) calloc (1, sizeof (struct File_buffer));

    file_handle (File_input);

    struct Line *Text = (struct Line*) calloc (File_input.num_of_lines, sizeof (struct Line));

    lines_separator (&File_input, Text);

    bubble_sort ((void*) Text, File_buffer.num_of_lines, &compare_strings);

    //-----------------------------------------------------------------------------

    for(int i = 0; i < num_of_lines; i++)
    {
        printf ("%s\n", (Text + i) -> begin_line);
    }

    fclose (file);

    file_printer (Text, num_of_lines);

    return 0;
}

//-----------------------------------------------------------------------------
