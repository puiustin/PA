#include <stdio.h>

void merge(int array[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int left_array[n1], right_array[n2];

    for (int i = 0; i < n1; i++)
        left_array[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        right_array[i] = array[middle + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (left_array[i] < right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int left, int right)
{
    int middle;
    if (left < right)
    {
        middle = (left + right) / 2;
        mergesort(array, left, middle);
        mergesort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main(void)
{
    int n;

    printf("Introduceti numarul de elemente ale vectorului: ");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        printf("Introduceti al %d-lea element: ", i + 1);
        scanf("%d", &v[i]);
    }
    mergesort(v, 0, n - 1);
    printf("Elementele vectorului sunt: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    return 0;
}