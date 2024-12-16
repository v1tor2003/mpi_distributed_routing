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

Here, the first line contains the number of nodes (and processes), then each line represents the weighted connection to its neighbors and `-` represents the absence of a direct connection between two nodes.

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

   Replace `7` with the number of nodes if the matrix is updated, do that for the constants.c file as well.

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

# Versão em português (Portuguese Version):
# Algoritmo de Roteamento Distribuído com MPI

Este projeto implementa um **Algoritmo de Roteamento Distribuído** usando a **Interface de Passagem de Mensagens (MPI)**. O algoritmo é baseado no protocolo de roteamento por vetor de distâncias, onde cada processo representa um nó em um grafo e calcula o caminho mais curto para todos os outros nós trocando iterativamente vetores de distância com seus vizinhos.

## Funcionalidades

- Implementa o protocolo de roteamento por vetor de distâncias de forma distribuída.
- Cada nó (processo) mantém e atualiza seu próprio vetor de distâncias.
- Utiliza MPI para comunicação entre processos.
- Exibe os vetores de distância finais de todos os nós após a convergência.

## Matriz de Adjacência

O programa utiliza um arquivo `.txt` fornecido pelo usuário contendo a matriz de adjacência para representar o grafo, conforme o exemplo:

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

Aqui, a primeira linha contém o número de nós (e processos), e cada linha subsequente representa as conexões ponderadas com seus vizinhos, onde `-` indica a ausência de conexão direta entre dois nós.

## Exemplo de Saída

Cada processo exibe seu vetor de distâncias final após a convergência do algoritmo. Exemplo de saída:

```
A: [ 0 3 12 4 2 11 5 ]
B: [ 3 0 10 7 1 9 3 ]
C: [ 12 10 0 16 11 1 7 ]
D: [ 4 7 16 0 6 15 9 ]
E: [ 2 1 11 6 0 10 4 ]
F: [ 11 9 1 15 10 0 6 ]
G: [ 5 3 7 9 4 6 0 ]
```

## Requisitos

- **Biblioteca MPI**: Certifique-se de ter uma implementação MPI instalada, como [OpenMPI](https://www.open-mpi.org/) ou [MPICH](https://www.mpich.org/).
- **Compilador C**: Por exemplo, `gcc`.

## Executando o Programa

1. Clone este repositório:
   ```bash
   git clone mpi_distributed_routing
   cd mpi_distributed_routing
   ```

2. Compile o programa:
   ```bash
   mpicc constants.c printer.c reader.c routing.c -o routing
   ```

3. Execute o programa com 7 processos (um para cada nó):
   ```bash
   mpirun -np 7 ./routing input.txt
   ```

   Substitua `7` pelo número de nós caso a matriz seja atualizada. Certifique-se de alterar o valor correspondente no arquivo `constants.c`.

4. Veja a saída para verificar os vetores de distâncias finais de todos os nós.

## Como Funciona

1. Cada nó inicia com seu vetor de distâncias inicializado para a linha correspondente da matriz de adjacência.
2. Os nós trocam vetores de distâncias com seus vizinhos.
3. Cada nó atualiza seu vetor de distâncias com base nas informações recebidas.
4. O processo se repete até que nenhuma atualização adicional seja necessária (convergência).

## Arquivos

- **`routing.c`**: Programa principal que implementa o algoritmo.
- **`printer.h`**: Arquivo de cabeçalho contendo definições de utilitários de impressão.
- **`reader.h`**: Arquivo de cabeçalho contendo definições de funções de leitura e alocação.
- **`printer.c`**: Arquivo contendo utilitários de impressão, usado pelo programa principal.
- **`reader.c`**: Arquivo contendo lógica de leitura de arquivos e alocação de memória, usado pelo programa principal.
- **`input.txt`**: Arquivo de entrada contendo o grafo estruturado como uma matriz de adjacência, conforme mencionado.
- **`constants.h`**: Arquivo de cabeçalho contendo definições de constantes, usado por printer, reader e pelo programa principal.
- **`constants.c`**: Arquivo contendo declarações de valores constantes.

## Observações

- Certifique-se de que o número de processos corresponde ao número de nós na matriz de adjacência.
- Saídas de depuração podem ser adicionadas para rastrear o cálculo passo a passo.

## Contribuindo

Contribuições são bem-vindas! Faça um fork do repositório e crie um pull request com suas alterações.

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.