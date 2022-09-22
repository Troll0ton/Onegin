#include "lines_handle.h"
#include "input_output.h"

//-----------------------------------------------------------------------------

char *buf;

//-----------------------------------------------------------------------------

int main ()
{
    FILE   *file  = fopen ("hamlet.txt", "rb");
    assert (file != NULL);

    int   buf_size = size_of_file (file) + 1;

    buf = (char*) calloc (buf_size, sizeof (char));

    file_reader (buf, buf_size, file);

    int *string_num = (int*) calloc (num_of_strings (buf, buf_size), sizeof (int));

    int num = line_detector (buf, buf_size, string_num);

    qsort (string_num, num, sizeof (int), &compare_strings);

    file_printer (buf, num, string_num);

    return 0;
}

//-----------------------------------------------------------------------------
