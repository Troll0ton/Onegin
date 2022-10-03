#include "lines_handle.h"
#include "input_output.h"
#include "main.h"

//-----------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    // -of -if
    assert (argc != 0 && argv != NULL);

    FILE   *file  = fopen (DATA_TEXT_FILE, "rb");  //open input file
    assert (file != NULL);

    struct File File_input = *(file_reader (&File_input, file));

    fclose (file);                                 //close input file

    // ?
    struct Line *Text = (struct Line*) calloc (File_input.num_of_lines, sizeof (struct Line));

    lines_separator (&File_input, Text);

    arg_handle (argc, argv, cmd_args, num_of_support_args, (void*) Text, File_input.num_of_lines);

    file_printer (Text, File_input.num_of_lines);

    free (Text);

    return 0;
}

//-----------------------------------------------------------------------------
