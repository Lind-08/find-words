#include <stdio.h>
#include <string.h>

struct
{
    char *word;
    int findsCount;
};


void checkFiles(int argc, char** argv)
{
    int i;
    for (i = 1; i < argc; i++)
    {
        FILE *fp;
        fp = fopen(argv[i],"rt");
        if (fp == 0)
        {
            printf("Can't open file ");
            puts(argv[i]);
            break;
        }
        fclose(fp);
    }
}


int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("No input files.\n");
    }
    else
    {
        checkFiles(argc, argv);
    }
    return 0;
}

