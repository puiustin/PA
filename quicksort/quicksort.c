// #include <stdio.h>
// #include <stdlib.h>

// void swap(int *a, int *b);
// void quicksort(int array[], int low, int high);
// int partition(int array[], int low, int high);

// int main(void)
// {
//     int array[] = {98112, 12382, 31283, 3482, 124378, 7437, 32732};
//     int size = sizeof(array) / sizeof(array[0]);
//     quicksort(array, 0, size - 1);
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", array[i]);
//     }
// }

// int partition(int array[], int low, int high)
// {
//     int pivot = array[high];
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         if (array[j] <= pivot)
//         {
//             i++;
//             swap(&array[i], &array[j]);
//         }
//     }
//     swap(&array[i + 1], &array[high]);
//     return i + 1;
// }

// void quicksort(int array[], int low, int high)
// {
//     int pivot;
//     if (low < high)
//     {
//         pivot = partition(array, low, high);
//         quicksort(array, low, pivot - 1);
//         quicksort(array, pivot + 1, high);
//     }
// }
// void swap(int *a, int *b)
// {
//     int aux;
//     aux = *a;
//     *a = *b;
//     *b = aux;
// }

// #include <stdio.h>
// #include <stdlib.h>

// void swap(int *a, int *b)
// {
//     int aux = *a;
//     *a = *b;
//     *b = aux;
// }

// int partition(int array[], int left, int right)
// {
//     int pivot = array[right];
//     int i = left - 1;
//     for (int j = left; j < right; j++)
//     {
//         if (array[j] <= pivot)
//         {
//             i++;
//             swap(&array[i], &array[j]);
//         }
//     }
//     swap(&array[i + 1], &array[right]);
//     return i + 1;
// }

// void qsort(int array[], int left, int right)
// {
//     int pivot;

//     if (left < right)
//     {
//         pivot = partition(array, left, right);
//         qsort(array, left, pivot - 1);
//         qsort(array, pivot + 1, right);
//     }
// }

// void citire(int array[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("Introduceti elementul %d: \n", i);
//         scanf("%d", &array[i]);
//     }
// }
// int main(void)
// {
//     int n;
//     int *v;
//     printf("Introduceti numarul de elemente ale vectorului: \n");
//     scanf("%d", &n);
//     v = malloc(n * sizeof(int));
//     citire(v, n);
//     qsort(v, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("Vectorul sortat este: ");
//         printf("%d ", v[i]);
//     }
//     return 0;
// }