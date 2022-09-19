#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrComparator (const void* first_str, const void* second_str);

int main()
{
    const int BUFSIZE = 300;

    FILE* file = fopen ("������.txt", "rb");
    char* buf = (char*) calloc (BUFSIZE, sizeof (char));

    int i = 0;
    int len = 0;

    char* text[BUFSIZE] = {};

    while (fgets (buf, BUFSIZE, file))
    {
        text[i] = strdup(buf);
        i++;
    }

    qsort ((char*) text, i - 1, sizeof (text[0]), &StrComparator);
    /*while (fread (buf, sizeof (char), BUFSIZE, file))
    {
        text[i] = strdup(buf);
        i++;
    } */
    /*
    char* p = text[i - 1];
    text[i - 1] = text[i - 2];
    text[i - 2] = p;  */

    for (int j = 0; j < i; j++) printf ("%s\n", text[j]);
}

int StrComparator (const void* first_str, const void* second_str)
{
    return strcmp ((const char*) first_str, (const char*) second_str);
}






