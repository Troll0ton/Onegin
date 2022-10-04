#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    FILE *file_in  = NULL;
    FILE *file_out = NULL;

    int (*comp_par)(void *first_p, void *second_p);

    assert (argc != 0 && argv != NULL);

    handle_args (argc,     argv,     cmd_args,  num_of_support_args,
                 &file_in,  &file_out, comp_par                       );

    if(file_in == NULL || file_out == NULL)
    {
        printf ("ERROR: files were specified incorrectly:\n");

        printf("%p %p", file_in, file_out);

        return 0;
    }

    struct File *File_input = file_reader (file_in);

    struct Line *Text = lines_separator (File_input);

    bubble_sort ((void*) Text, File_input->num_of_lines, comp_par);

    fclose (file_in);

    file_printer (Text, File_input->num_of_lines, file_out);

    purificate_mem (Text, File_input);

    return 0;
}

//-----------------------------------------------------------------------------
