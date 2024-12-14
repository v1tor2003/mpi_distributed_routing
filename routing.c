#include "reader.h"
#include "printer.h"
#include <stdio.h>
#include <mpi.h>

int* init_dist(int**graph, int rank){
    int* dist = (int*) malloc(N * sizeof(int));
    
    for(size_t i = 0; i < N; i++)
        dist[i] = graph[rank][i];

    dist[rank] = 0;
    return dist;
}

void do_routing(int rank, int** graph, int* dist){
    int updated;
    do
    {
        updated = 0;
        for(size_t neighbor = 0; neighbor < N; neighbor++){
            if(neighbor != rank && graph[rank][neighbor] != INF){
                int neighbor_dist[N];
                MPI_Sendrecv(dist, N, MPI_INT, neighbor, 0,
                             neighbor_dist, N, MPI_INT, neighbor, 0, 
                             MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                for(size_t i = 0; i < N; i++){
                    if(neighbor_dist[i] != INF && dist[neighbor] != INF
                        && dist[i] > dist[neighbor] + neighbor_dist[i] 
                    ) {
                        dist[i] = dist[neighbor] + neighbor_dist[i];
                        updated = 1;
                    }
                }
            }
        }
        MPI_Allreduce(MPI_IN_PLACE, &updated, 1, MPI_INT, MPI_LOR, MPI_COMM_WORLD);
    } while (updated);   
}

int main (int argc, char** argv){
    if(argc <= 1){
        fprintf(stderr, "Arquivo de entrada nao especificado. Saindo...\n");
        return -1;
    }
    const char* filename = argv[1];
    int rank, size;

    int** graph = R_read(filename, &size);
    if(!graph) return -1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(size != N){
        if(rank == 0)
            fprintf(stderr, "O numero de processos deve ser %d.\n", N);
        MPI_Finalize();
        return -1;
    }    

    int* dist = init_dist(graph, rank);
    do_routing(rank, graph, dist);
    P_print_vector_to_screen(dist, rank, TRUE);

    MPI_Finalize();
    return 0;
}