#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrComparator (const void* first_str, const void* second_str);

int main()
{
    const int BUFSIZE = 100;

    FILE* file = fopen ("hamlet.txt", "rb");
    char* buf = (char*) calloc (BUFSIZE, sizeof (char));

    int i   = 0;
    int len = 0;

    char* text[BUFSIZE] = {};

    while (fgets (buf, BUFSIZE, file))
    {
        text[i] = strdup (buf);
        i++;
    }

    qsort ((char*) text, i - 1, sizeof (text[0]), &StrComparator);

    /*while (fread (buf, sizeof (char), BUFSIZE, file))
    {
        text[i] = strdup(buf);
        i++;
    } */

    for (int j = 0; j < i; j++) printf ("%s", text[j]);

    printf ("\n");
}

int StrComparator (const void* first_str, const void* second_str)
{
    return strcmp ((const char*) first_str, (const char*) second_str);
}

