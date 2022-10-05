#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    assert (argc != 0 && argv != NULL);

    FILE *file_in  = NULL;
    FILE *file_out = NULL;

    int (*comp_par)(void *first_p, void *second_p);

    handle_args (argc,     argv,      cmd_args,  num_of_support_args,
                 &file_in, &file_out, &comp_par                     );

    if(file_in == NULL || file_out == NULL)
    {
        printf ("ERROR: files were specified incorrectly:\n");

        return 0;
    }

    struct File *File_input = file_reader (file_in);

    struct Line *Text = lines_separator (File_input);

    bubble_sort ((void*) Text, File_input->num_of_lines, comp_par);

    file_printer (Text, File_input->num_of_lines, file_out);

    purificate_mem (Text, File_input);

    fclose (file_in);

    fclose (file_out);

    return 0;
}

//-----------------------------------------------------------------------------
