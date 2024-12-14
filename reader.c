#include "reader.h"
#include <string.h>

void R_free(int** matrix, int* size) {
    for (int i = 0; i < *size; i++) free(matrix[i]);
    free(matrix);
}

char* R_abort(const char* errmsg, FILE* file){
    fprintf(stderr, "%s\n",errmsg);
    if(file) fclose(file);
    return NULL;
}

void R_alloc(int** matrix, FILE* file,int* size){
    for(int i = 0; i < *size; i++){
        matrix[i] = (int*)malloc(*size * sizeof(int));
        if(!matrix[i]){
            R_free(matrix, size);
            R_abort("Erro ao alocar memoria.", file);
        }
    }
}

void R_copy(int** matrix, FILE* file, int* size){
    for(int i = 0; i < *size; i++){
        for(int j = 0; j < *size; j++){
            char buffer[4];
            fscanf(file, "%s", buffer);

            if(strcmp(buffer, "-") == 0)
                matrix[i][j] = INF;
            else 
                matrix[i][j] = atoi(buffer);
        }
    }
}

int** R_read(const char* filename, int* size){
    FILE* file = fopen(filename, "r");
    if(!file) return (int**)R_abort("Erro ao abrir arquivo.", NULL);
        
    if(fscanf(file, "%d", size) != 1) 
        return (int**)R_abort("Erro ao ler tam do grafo.", file);
     
    int** matrix = (int**)malloc(*size * sizeof(int*));
    if(!matrix)
       return (int**)R_abort("Erro ao alocar memoria.", file);

    R_alloc(matrix, file, size);
    R_copy(matrix, file, size);
    fclose(file);
    return matrix;
}