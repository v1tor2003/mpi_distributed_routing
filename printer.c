#include "printer.h"

void P_print_to_screen(int** matrix, int size){
    for(size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++){
            if(matrix[i][j] == INF)
                printf("∞ ");
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n"); 
    }
}

void P_print_vector_to_screen(int *vector, int rank, int create_label) {
    if(create_label)
        printf("%c: [ ", rank + 'A');
    else
        printf("%d: [ ", rank);
    
    for (size_t i = 0; i < N; i++) {
        if (vector[i] == INF)
            printf("∞ ");
        else
            printf("%d ", vector[i]);
    }
    printf("]\n");
}
