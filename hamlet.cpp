#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

//-----------------------------------------------------------------------------

int file_total_lenght (FILE *file);

int file_reader (char *file_buffer, int buffer_size, FILE *file);

int point_lines_Ctor (char *buffer, int buffer_size, char* *pointer_line);

int compare_strings (const void *first_i, const void *second_i);

//-----------------------------------------------------------------------------

/*struct Line
{
    char *Pbegin_line;

    int line_length;
};*/

//-----------------------------------------------------------------------------

int main ()
{
    FILE   *file  = fopen ("hamlettest.txt", "rb");
    assert (file != NULL);

    int buffer_size = file_total_lenght (file);

    char *file_buffer = (char*) calloc (buffer_size, sizeof (char));

    file_reader (file_buffer, buffer_size, file);

    char *pointer_line[100] = {0};

    int num_of_lines = point_lines_Ctor (file_buffer, buffer_size, pointer_line);

    qsort (pointer_line, num_of_lines, sizeof (char*), &compare_strings);

    for(int i = 0; i < num_of_lines; i++)
    {
        printf ("%s\n", *(pointer_line + i));
    }

    //file_printer (buf, num, string_num);

    return 0;
}

//-----------------------------------------------------------------------------

int file_total_lenght (FILE *file)
{
    struct stat file_stat = {0};

    fstat (fileno (file), &file_stat);

    return (file_stat.st_size + 1);
}

//-----------------------------------------------------------------------------

int point_lines_Ctor (char *buffer, int buffer_size, char* *pointer_line)
{
    int num_line = 0;

    char *line_begin = buffer;

    if (*(buffer) == '\r' || *(buffer) == '\n')
    {
        *(buffer) = '\0';
        line_begin++;
    }

    for(int i = 1; i <= buffer_size; i++)
    {
        if (*(buffer + i) == '\r' ||
            *(buffer + i) == '\n')
        {
            *(buffer + i) = '\0';
        }

        if(*(buffer + i) == '\0')
        {
            if(*(buffer + i - 1) != '\0')
            {
                *(pointer_line + num_line) = line_begin;

                line_begin = buffer + i + 1;
                num_line++;
            }

            else
            {
                line_begin++;
            }
        }
    }

    if(*(buffer + buffer_size - 2) != '\0')
    {
        *(pointer_line + num_line) = line_begin;
    }

    printf ("%d\n", num_line);

    return (num_line);

}

//-----------------------------------------------------------------------------

int file_reader (char *file_buffer, int buffer_size, FILE *file)
{
    fread (file_buffer, sizeof (char), buffer_size, file);

    *(file_buffer + buffer_size - 1) = '\0';

    return 0;
}

//-----------------------------------------------------------------------------

int compare_strings (const void *first_i, const void *second_i)
{
    char *first_str  = *(char**) first_i;
    char *second_str = *(char**) second_i;

    return strcmp (first_str, second_str);
}

//-----------------------------------------------------------------------------

