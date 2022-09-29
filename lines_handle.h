//! @file lines_handle.h

#ifndef   LINES_HANDLE_H
#define   LINES_HANDLE_H

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

//-----------------------------------------------------------------------------

struct Line
{
// P?
    char *Pbegin_line;

    int line_lenght;
};

//-----------------------------------------------------------------------------

int compare_strings  (const void *first_p, const void *second_p);

int point_lines_Ctor (char *buffer, int buffer_size, struct Line *Text);

//-----------------------------------------------------------------------------

#endif //LINES_HANDLE_H
