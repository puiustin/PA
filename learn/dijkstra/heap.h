#ifndef heap_h
#define heaph_h

typedef struct
{
    int *vec;
    int size, capacity;
} Heap;

Heap *create(int capacitate);
int parent(Heap *h, int i);
int max(Heap *h);
int min(Heap *h);
int left_child(Heap *h, int i);
int right_child(Heap *h, int i);
void resize(Heap *h);
void insert(Heap *h, int x);
void delete_heap(Heap **h);
void printHeap(Heap *h);
void heapify_down(Heap *h, int i);
void heapify_up(Heap *h, int i);
void heapsort(Heap *h, int *buf, int n);
void populate(Heap *h, int *buf, int n);

#endif