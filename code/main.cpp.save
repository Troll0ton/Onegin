#include "../include/input_output.h"
#include "../include/lines_handle.h"

//-----------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    Arg_handler_res Arg_res_par = {NULL, NULL, NULL};

    handle_args (argc,                 argv,       cmd_args,
                 num_of_support_args, &Arg_res_par          );

    if(Arg_res_par.file_in == NULL || Arg_res_par.file_out == NULL)
    {
        printf ("ERROR: files were specified incorrectly:\n");

        return 0;
    }

    File *File_input = file_reader (Arg_res_par.file_in);
    Line *Text = lines_separator   (File_input);

    bubble_sort ((void*) Text, File_input->num_of_lines, Arg_res_par.comp_par);

    file_printer (Text, File_input->num_of_lines, Arg_res_par.file_out);

    Text_dtor (Text);
    File_dtor (File_input);

    fclose (Arg_res_par.file_in);
    fclose (Arg_res_par.file_out);

    return 0;
}

//-----------------------------------------------------------------------------
