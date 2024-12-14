#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

char* R_abort(const char* errmsg, FILE* file);
void R_alloc(int** matrix, FILE* file, int* size);
void R_copy(int** matrix, FILE* file, int* size);
void R_free(int** matrix, int* size);
int** R_read(const char* filename, int* size);

#endif // READER_H