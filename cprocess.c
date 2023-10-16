#include<stdio.h>
#include<stdlib.h>
#include "compiler.h"

struct compile_process* compile_process_create(const char* filename, const char* filename_out, int flags)
{
    FILE* file = fopen(filename, "r");
    if (!file)
        return NULL;

    FILE* file_out = NULL;
    if (filename_out)
    {
        fopen(filename_out, "w");
        if (!file_out)
            return NULL;
    }

    struct compile_process* process = calloc(1, sizeof(struct compile_process));
    process->flags = flags;
    process->cfile.fp = file;
    process->ofile = file_out;
}