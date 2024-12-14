#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

void P_print_to_screen(int** matrix, int size);
void P_print_vector_to_screen(int *vector, int rank, int create_label);

#endif // PRINTER_H