#include "input_output.h"

//-----------------------------------------------------------------------------

int num_of_strings (char *file_buffer, int buffer_size)
{
    int string_counter = 0;

    for(int i = 0; i < buffer_size; i++)
    {
        if(file_buffer[i] == '\n')
        {
            string_counter++;
        }
    }

    return string_counter + 1;
}

//-----------------------------------------------------------------------------

// file_size
int file_total_lenght (FILE *file)
{
    struct stat file_stat = {0};

    fstat (fileno (file), &file_stat);

    // ??
    return file_stat.st_size + 1;
}

//-----------------------------------------------------------------------------

int file_reader (char *file_buffer, int buffer_size, FILE *file)
{
    fread (file_buffer, sizeof (char), buffer_size, file);

    *(file_buffer + buffer_size - 1) = '\0';

    return 0;
}

//-----------------------------------------------------------------------------

int file_printer (struct Line *Text, int num_of_lines) //Close exit file!
{
    printf ("Cool!");
    /*
    FILE   *file1  = fopen ("hamlet1.txt", "w+");
    assert (file1 != NULL);

    for(int j = 0; j < num_of_lines; j++)
    {
        fprintf (file1, "\n%s", (Text + j) -> Pbegin_line);
    }

    fclose (file1);
    */

    return 0;
}

//-----------------------------------------------------------------------------
