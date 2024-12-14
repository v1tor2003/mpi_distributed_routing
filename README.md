# Distributed Routing Algorithm with MPI

This project implements a **Distributed Routing Algorithm** using the **Message Passing Interface (MPI)**. The algorithm is based on the distance-vector routing protocol, where each process represents a node in a graph and computes the shortest path to all other nodes by iteratively exchanging distance vectors with its neighbors.

## Features

- Implements the distance-vector routing protocol in a distributed manner.
- Each node (process) maintains and updates its own distance vector.
- Uses MPI for inter-process communication.
- Prints the final distance vectors for all nodes after convergence.

## Adjacency Matrix

The program uses a user provided input .txt file containing the adjacency matrix to represent the graph, as it follows:

```
7 
0 5 - 4 2 - 5
5 0 - - 1 - 3
- - 0 - - 1 7
4 - - 0 - - -
2 1 - - 0 - 8
- - 1 - - 0 6
5 3 7 - 8 6 0
```

Here, the first line contains the number of nodes, then each line represents the weighted connection to its neighbors and `-` represents the absence of a direct connection between two nodes.

## Output Example

Each process outputs its final distance vector after the algorithm converges. An example output:

```
A: [ 0 3 12 4 2 11 5 ]
B: [ 3 0 10 7 1 9 3 ]
C: [ 12 10 0 16 11 1 7 ]
D: [ 4 7 16 0 6 15 9 ]
E: [ 2 1 11 6 0 10 4 ]
F: [ 11 9 1 15 10 0 6 ]
G: [ 5 3 7 9 4 6 0 ]
```

## Requirements

- **MPI library**: Ensure you have an MPI implementation installed, such as [OpenMPI](https://www.open-mpi.org/) or [MPICH](https://www.mpich.org/).
- **C compiler**: For example, `gcc`.

## Running the Program

1. Clone this repository:
   ```bash
   git clone mpi_distributed_routing
   cd mpi_distributed_routing
   ```

2. Compile the program:
   ```bash
   mpicc constants.c printer.c reader.c routing.c -o routing
   ```

3. Run the program with 7 processes (one for each node):
   ```bash
   mpirun -np 7 ./routing input.txt
   ```

   Replace `7` with the number of nodes if the matrix is updated.

4. View the output to verify the final distance vectors for all nodes.

## How It Works

1. Each node starts with its distance vector initialized to the corresponding row of the adjacency matrix.
2. Nodes exchange distance vectors with their neighbors.
3. Each node updates its distance vector based on the received information.
4. The process repeats until no further updates are needed (convergence).

## Files

- **`routing.c`**: The main program implementing the algorithm.
- **`printer.h`**: Header file containg printing utilities definitions.
- **`reader.h`**: Header file containg reading and allocation function definitions.
- **`printer.c`**: File containg printing utilities, used by the main program.
- **`reader.c`**: File containg reading file and memory allocation logic, used by the main program.
- **`input.txt`**: Input file containg the graph structured as an adjacency matrix, as mentioned before.
- **`constants.h`**: Header file containg constants definitions, used by printer, reader and main program.
- **`constants.c`**: File containg constants values declarations.

## Notes

- Ensure the number of processes matches the number of nodes in the adjacency matrix.
- Debugging output can be added to trace the computation step-by-step.

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
