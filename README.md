# PA — Proiectarea Algoritmilor

Laborator assignments and practice exercises in C, covering fundamental data structures and algorithms.

## Structure

| Directory | Topic |
|---|---|
| `laborator1/` | Vectors, matrices, functions (learn1–3) |
| `laborator2/` | File I/O |
| `laborator3/` | Merge sort |
| `laborator4/` | Linked lists |
| `laborator5/` | Stacks and queues |
| `laborator6/` | Trees (with stack-based traversal) |
| `laborator7/` | Binary search trees (BST) |
| `laborator9/` | Graphs |
| `laborator10/` | Dijkstra's shortest path algorithm |
| `laborator11/` | Knapsack problem (Prob_Rucsac) |
| `laborator12/` | N-Queens problem |
| `learn/` | Scratch/practice implementations of the above topics (BST, Dijkstra, graphs, linked lists, quicksort, knapsack, N-Queens, trees, binary files) |
| `examen/` | Exam exercise (`cox`) |

Each lab directory is a self-contained C project: a `main.c` driver plus paired `.c`/`.h` files implementing the data structure or algorithm, along with a `makefile`.

## Building and running

Each project builds with its local `makefile`:

```sh
cd laborator10
make        # compiles all .c files into ./run
./run
make clean  # removes the compiled binary
```

## Requirements

- GCC
- `make`
