#include "input_output.h"

//-----------------------------------------------------------------------------

void file_handle (struct File_buffer *File_input)
{
    FILE   *file  = fopen ("hamlettest.txt", "rb");
    assert (file != NULL);

    (*File_input).file_size = file_size (file) + 1;

    file_reader (File_input, file);

    (*File_input).num_of_lines = num_of_strings (File_input);
}

//-----------------------------------------------------------------------------

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

    *((*File_input).file_data + (*File_input).file_size - 1) = '\0';

    return 0;
}

//-----------------------------------------------------------------------------

int file_printer (struct Line *Text, int num_of_lines) //OPEN and CLOSE exit file!
{
    printf ("Cool!");

    FILE   *file1  = fopen ("hamlet1.txt", "w+");
    assert (file1 != NULL);

    for(int j = 0; j < num_of_lines; j++)
    {
        char *pointline = Text[j].begin_line;
        fprintf (file1, "\n%s", pointline);
    }

    fclose (file1);

    return 0;
}

//-----------------------------------------------------------------------------
