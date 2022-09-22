#include "lines_handle.h"

//-----------------------------------------------------------------------------

int compare_strings (const void *first_i, const void *second_i)
{
    int i1 = *(const int*) first_i;
    int i2 = *(const int*) second_i;

    char *first_str  = buf + i1;
    char *second_str = buf + i2;

    return strcmp (first_str, second_str);
}


//-----------------------------------------------------------------------------

int line_detector (char *buffer_in, int buf_size, int *string_num)
{
    int kol = 0;
    int posit = 0;

    for(int i = 0; i <= buf_size; i++)
    {
        if(*(buffer_in + i) == '\n' || *(buffer_in + i) == '\r')
        {
            if(*(buffer_in + i - 1) != '\n' && *(buffer_in + i - 1) != '\r' && *(buffer_in + i - 1) != '\0')
            {
                *(string_num + kol) = posit;
                posit = i + 1;
                kol++;
            }

            else
            {
                posit++;
            }

            *(buffer_in + i) = '\0';
        }

        else
        {
            if(i == buf_size)
            {
                if(*(buffer_in + i - 1) != '\n' && *(buffer_in + i - 1) != '\r' && *(buffer_in + i - 1) != '\0')
                {
                    *(string_num + kol) = posit;
                }
            }
        }
    }

    return (kol + 1);
}

//-----------------------------------------------------------------------------
