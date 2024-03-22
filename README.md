# Graph-Project

This repository was created to store the implementation of various graph algorithms as part of a project for the Graphs discipline at Universidade Federal de Alagoas.

## Antônio Maria Cardoso Wagner


## Algorithms Implemented

The project includes implementations of the following graph algorithms:

- **Kosaraju's Algorithm:** This algorithm is used to find strongly connected components in a directed graph. It utilizes depth-first search (DFS) to perform two passes over the graph.

- **Dijkstra's Algorithm:** Dijkstra's algorithm is a shortest-path algorithm used to find the shortest path between nodes in a weighted graph. It employs a greedy strategy to iteratively find the shortest path from a source node to all other nodes.

- **Kruskal's Algorithm:** Kruskal's algorithm is used to find the minimum spanning tree (MST) of a connected, undirected graph. It operates by selecting edges in increasing order of weight while ensuring that no cycles are formed.

- **Bellman-Ford Algorithm:** The Bellman-Ford algorithm is used to find the shortest paths from a single source vertex to all other vertices in a weighted graph with negative edge weights. It iterates over all edges multiple times, relaxing them to find the shortest paths.

- **Prim's Algorithm:** Prim's algorithm is another method for finding the minimum spanning tree (MST) of a connected, undirected graph. It starts from an arbitrary node and adds the cheapest edge to the growing tree at each step until all nodes are included.

## File Structure

The project's file structure is organized as follows:

- **C++ Files** This directory contains the source code files written in C++ for each algorithm.
  - `kosaraju.cpp`
  - `dijkstra.cpp`
  - `kruskal.cpp`
  - `bellman.cpp`
  - `prim.cpp`

- **makefile:** This file is used to compile the source code and generate the executable files.

- **Testes** In Bellman-Ford algorithm there is a folder that contains 20 tests.

## How to Run

To run any of the implemented algorithms, follow these steps:

1. Clone or download the repository.
2. Navigate to the directory containing the source code and executables.
3. Open a terminal or command prompt.
4. Compile the desired algorithm using the provided makefile.
5. Execute the compiled program. For example:
6. Follow the prompts to input the graph data or use pre-defined graphs stored in files.

## Why C++?

C++ was chosen for this project due to its efficiency and performance in handling graph algorithms, especially for large datasets. Its low-level features provide greater control over memory management and data structures, which are crucial for implementing complex graph algorithms efficiently.

Thank you for exploring our Graph Algorithms Project! Feel free to contribute, provide feedback, or use the implementations for your own projects.

Have a great day and happy coding! :)

[Repository Link](https://github.com/AnriaW/Graph_Theory/tree/main)

## References

- [GeeksforGeeks - Graph Algorithms](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
- [C++ Reference - Standard Template Library (STL)](https://en.cppreference.com/w/)
- [Stack Overflow - C++ Programming](https://stackoverflow.com/questions/tagged/c%2b%2b)
- [Codecademy - Learn C++](https://www.codecademy.com/learn/learn-c-plus-plus)
- [Coursera - Algorithms Specialization](https://www.coursera.org/specializations/algorithms)
