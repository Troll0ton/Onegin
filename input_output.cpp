#include "input_output.h"

//-----------------------------------------------------------------------------

int num_of_strings (char *buffer_in, int buf_size)
{
    int string_counter = 0;

    for(int i = 0; i < buf_size; i++)
    {
        if(buffer_in[i] == '\n')
        {
            string_counter++;
        }
    }

    return string_counter + 1;
}

//-----------------------------------------------------------------------------

int size_of_file (FILE *file)
{
    struct stat buffer;
    fstat (fileno (file), &buffer);

    return buffer.st_size;

    fclose (file);
}

//-----------------------------------------------------------------------------

int file_reader (char *buffer_in, int buf_size, FILE *file)
{
    fread (buffer_in, sizeof (char), buf_size, file);
    *(buffer_in + buf_size) = '\0';

    int text_size = num_of_strings (buffer_in, buf_size);

    return text_size;
}

//-----------------------------------------------------------------------------

int file_printer (char *buffer_in, int num, int *string_num)
{
    FILE   *file1  = fopen ("hamlet1.txt", "w+");
    assert (file1 != NULL);

    for(int j = 0; j < num; j++)
    {
        fprintf (file1, "\n%s", buffer_in + *(string_num + j));
    }

    fclose (file1);

    return 0;
}

//-----------------------------------------------------------------------------
