#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

/*int file_total_lenght (FILE *file);

int file_reader (char *file_buffer, int buffer_size, FILE *file);

int point_lines_Ctor (char *buffer, int buffer_size, struct Line *Text);

int compare_strings (const void *first_p, const void *second_p);

int num_of_strings (char *file_buffer, int buffer_size);

int file_printer (struct Line *Text, int num_of_lines);  */

//-----------------------------------------------------------------------------

int main ()
{
    FILE   *file  = fopen ("hamlettest.txt", "rb");
    assert (file != NULL);

    int buffer_size = file_total_lenght (file);

    char *file_buffer = (char*) calloc (buffer_size, sizeof (char));

    file_reader (file_buffer, buffer_size, file);

    int num_of_lines = num_of_strings (file_buffer, buffer_size);

    struct Line *Text = (struct Line*) calloc (num_of_lines, sizeof (struct Line));

    point_lines_Ctor (file_buffer, buffer_size, Text);

    qsort (Text, num_of_lines, sizeof (struct Line), &compare_strings);

    for(int i = 0; i < num_of_lines; i++)
    {
        printf ("%s\n", (Text + i) -> Pbegin_line);
    }

    //file_printer (buf, num, string_num);

    return 0;
}

/*
//-----------------------------------------------------------------------------

int file_total_lenght (FILE *file)
{
    struct stat file_stat = {0};

    fstat (fileno (file), &file_stat);

    return (file_stat.st_size + 1);
}

//-----------------------------------------------------------------------------

int point_lines_Ctor (char *buffer, int buffer_size, struct Line *Line_p)
{
    int num_line = 0;

    char *line_begin = buffer;

    int cur_len = 0;

    for(int i = 0; i < buffer_size; i++)
    {
        if(*(buffer + i) == '\n')
        {
            *(buffer + i) = '\0';

            (Line_p + num_line) -> Pbegin_line = (buffer + i - cur_len);

            cur_len = 0;
            num_line++;
        }

        else
        {
            cur_len++;
        }
    }

    (Line_p + num_line) -> Pbegin_line = (buffer + buffer_size - cur_len);
    num_line++;

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

int compare_strings (const void *first_p, const void *second_p)
{
    struct Line *first_line  = (struct Line*) first_p;
    struct Line *second_line = (struct Line*) second_p;

    return strcmp (first_line -> Pbegin_line, second_line -> Pbegin_line);
}

//----------------------------------------------------------------------------

int num_of_strings (char *file_buffer, int buffer_size)
{
    int string_counter = 0;

    for(int i = 0; i < buffer_size; i++)
    {
        if(*(file_buffer + i) == '\n')
        {
            string_counter++;
        }
    }

    return string_counter + 1;
}

//-----------------------------------------------------------------------------

int file_printer (struct Line *Text, int num_of_lines)
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
*/




