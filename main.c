#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
    char *word;
    int findsCount;
}record;


typedef struct word_array
{
    record **array;
    unsigned int length;
    unsigned int capacity;
}word_array;

void init_array(word_array *array)
{
    array->capacity = 1;
    array->length = 0;
    array->array = (record**)malloc(sizeof(record*) * array->capacity);
}


void delete_array(word_array* array)
{
    unsigned int i;
    free(array->array);
}

void resize_array(word_array* array)
{
    record** temp = (record**)malloc(sizeof(record*) * array->capacity);
    memccpy(temp, array->array,sizeof(record*),array->capacity);
    array->capacity = array->capacity * 2;
    array->array = (record**)realloc(array->array, sizeof( record*) * array->capacity);
    memccpy(array->array,temp,sizeof( record*),array->length);
}

void add_record( word_array *array,  record* rec)
{
    if (array->length == array->capacity)
        resize_array(array);
    array->array[array->length] = rec;
    array->length++;
}

record* find_record(word_array* array, char* word)
{

}

record* get_record(word_array* array, int position)
{
    if (position >= array->length)
        return NULL;
    else
        return array->array[position];
}

void parceFile(FILE* file, word_array *array)
{

}

int checkFiles(int argc, char** argv)
{
    int i;
    int res = 1;
    for (i = 1; i < argc; i++)
    {
        FILE *fp;
        fp = fopen(argv[i],"rt");
        if (fp == 0)
        {
            printf("Can't open file ");
            puts(argv[i]);
            res = 0;
        }
        fclose(fp);
    }
    return res;
}


int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("No input files.\n");
    }
    else
    {
        if (checkFiles(argc, argv))
        {

        }
    }
    return 0;
}

