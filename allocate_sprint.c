#include <stdlib.h>
#include <stdio.h>
#include "allocate_sprint.h"

int varargs_allocate_sprintf(char **strp, const char *fmt, va_list ap){
    va_list ap1;
    size_t size;
    char *buffer;

    va_copy(ap1, ap);
    size = vsnprintf(NULL, 0, fmt, ap1) + 1;
    va_end(ap1);
    buffer = calloc(1, size);

    if (!buffer)
        return -1;

    *strp = buffer;

    return vsnprintf(buffer, size, fmt, ap);
}

int allocate_sprintf(char **strp, const char *fmt, ...){
    int error;
    va_list ap;

    va_start(ap, fmt);
    error = varargs_allocate_sprintf(strp, fmt, ap);
    va_end(ap);

    return error;
}