#include <stdio.h>

void display(int* arr, int size);
void bubble_sort(int* arr, int size);
void merge_sort(int* arr, int l, int r);
void merge(int* arr, int l, int m, int r);
void swap(int* x, int* y);

int main()
{
    int arr[] = {15, 25, 6, 29, 65, 32, 17, 89, 53, 41};
    merge_sort(arr, 0, 9);
    display(arr, 10);
    return 0;
}


void display(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void bubble_sort(int* arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

void merge_sort(int* arr, int l, int r)
{
    if (l == r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
    return;
}

void merge(int* arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int arr1[n1], arr2[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
    {
        arr1[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        arr2[j] = arr[m + 1 + j];
    }

    i = j = 0; k = l;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            k++; i++;
        }
        else
        {
            arr[k] = arr2[j];
            k++; j++;
        }
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        k++; i++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        k++; j++;
    }
    return;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}