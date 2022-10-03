#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

void file_handle (struct File_buffer *File_input, FILE *file)
{

    // one function
    File_input->file_size = file_size (file) + 1;

    // ->
    // buffer
    (*File_input).file_data = (char*) calloc ((*File_input).file_size, sizeof (char));

    file_reader (File_input, file);

    // ??
    // main

    (*File_input).num_of_lines = num_of_strings (File_input);
}

//-----------------------------------------------------------------------------

// get_num_of_strs
int num_of_strings (struct File_buffer *File_input)
{
    int string_counter = 0;

    for(int i = 0; i < (*File_input).file_size; i++)
    {
        if((*File_input).file_data[i] == '\n')
        {
            string_counter++;
        }
    }

    string_counter++;

    return string_counter;
}

//-----------------------------------------------------------------------------

// handle_args
void arg_handle (int argc,          char* argv[],           const struct Option cmd[],
                 int options_range, void* string_array,     int          num_of_lines)
{
    assert (argc != 0);
    assert (argv != NULL);
    assert (cmd  != NULL);

    for(int arg_num = 1; arg_num < argc; arg_num++)
    {
        for(int i = 0; i < options_range; i++)
        {
            if(strcmp (argv[arg_num], cmd[i].opt_name) == 0) //or divide options_range into any blocks
            {
                // ?
                bubble_sort (string_array, num_of_lines, cmd[i].func);
            }
        }
    }
}

//-----------------------------------------------------------------------------

// get_file_size()

int file_size (FILE *file)
{
    struct stat file_stat = {0};

    fstat (fileno (file), &file_stat);

    return file_stat.st_size;
}

//-----------------------------------------------------------------------------

int file_reader (struct File_buffer *File_input, FILE *file)
{
    fread ((*File_input).file_data, sizeof (char), (*File_input).file_size, file);

    // File_input->file_data[File_input->file_size - 1] = '\0';
    *((*File_input).file_data + (*File_input).file_size - 1) = '\0';

    return 0;
}

//-----------------------------------------------------------------------------

int file_printer (struct Line *Text, int num_of_lines) //OPEN and CLOSE exit file!
{
    FILE   *file_out  = fopen (OUT_FILE, "w+");
    assert (file_out != NULL);

    // i
    for(int j = 0; j < num_of_lines; j++)
    {
        fprintf (file_out, "\n%s", Text[j].begin_line);
    }

    fclose (file_out);

    return 0;
}

//-----------------------------------------------------------------------------
