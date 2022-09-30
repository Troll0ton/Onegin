#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

int main ()
{
    FILE   *file  = fopen ("hamlettest.txt", "rb");
    assert (file != NULL);

    struct File_buffer File_input = {0};

    file_handle (&File_input, file);

    fclose (file);

    struct Line *Text = (struct Line*) calloc (File_input.num_of_lines, sizeof (struct Line));

    lines_separator (&File_input, Text);

    bubble_sort ((void*) Text, File_input.num_of_lines, &compare_strings_end); //compare_strings_begin

    file_printer (Text, File_input.num_of_lines);

    return 0;
}

//-----------------------------------------------------------------------------
