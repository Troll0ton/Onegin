#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

//-----------------------------------------------------------------------------

int  compare_strings (const void *first_str, const void *second_str);

int  num_of_strings (char *buf, int buf_size);

int  size_of_file (FILE *file);

int  file_reader (char *buf, int buf_size, FILE *file);

void split_strings (char *buf, int buf_size, struct String* Text);

//-----------------------------------------------------------------------------

struct String
{
    char *str;

    int   str_len;
};

//-----------------------------------------------------------------------------

int main ()
{
    FILE   *file  = fopen ("hamlet.txt", "rb");
    assert (file != NULL);

    int   buf_size = size_of_file (file);

    char *buf = (char*) calloc (buf_size, sizeof (char));

    file_reader (buf, buf_size, file);

    struct String Text[11];

    split_strings (buf, buf_size, Text);

    printf ("\n%s %d\n", Text[0].str, Text[0].str_len);
}

//-----------------------------------------------------------------------------

int compare_strings (const void *first_str, const void *second_str)
{
    return strcmp ((const char*) first_str, (const char*) second_str);
}

//-----------------------------------------------------------------------------

int num_of_strings (char *buf, int buf_size)
{
    int string_counter = 0;

    for(int i = 0; i < buf_size; i++)
    {
        if(buf[i] == '\n')
        {
            string_counter++;
        }
    }

    return string_counter + 1;
}

//-----------------------------------------------------------------------------

void split_strings (char *buf, int buf_size, struct String* Text)
{
    int max_buf_size = 100;
    int str_size = 0;
    int Text_index = 0;

    char *current_string = (char*) calloc (max_buf_size, sizeof (char));

    for(int i = 0; i < buf_size; i++)
    {
        if(*(buf + i) != '\0')
        {
            current_string[str_size] = *(buf + i);
            str_size++;

            if(str_size == max_buf_size)
            {
                max_buf_size *= 2;
                current_string = (char*) realloc (current_string, sizeof (char) * max_buf_size);
            }
        }

        else
        {
            current_string[str_size] = '\0';
            str_size++;

            char *pointer_copy = current_string;
            Text[Text_index].str = pointer_copy;
            Text[Text_index].str_len = str_size - 1;

            free (current_string);
            max_buf_size = 100;
            char *current_string = (char*) calloc (max_buf_size, sizeof (char));

            str_size = 0;
            Text_index++;
        }
    }
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

int file_reader (char *buf, int buf_size, FILE *file)
{
    fread (buf, sizeof (char), buf_size, file);
    printf ("%s", buf);

    int text_size = num_of_strings (buf, buf_size);

    return text_size;
}

//-----------------------------------------------------------------------------
