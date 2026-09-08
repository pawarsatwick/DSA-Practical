#include <stdio.h>
void BubbleSort(int arr[], int n);
void InsertionSort(int arr[], int n);
void QuickSort(int arr[], int low, int high);
int Partition(int arr[], int low, int high);
void MergeSort(int arr[], int low, int high);
void Merge(int arr[], int low, int mid, int high);
int main()
{
    int arr[5];
    int n = 5;
    int choice;
    int i;
    printf("Enter 5 elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Partition Sort (Quick Sort)\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            BubbleSort(arr, n);
            break;

        case 2:
            InsertionSort(arr, n);
            break;

        case 3:
            QuickSort(arr, 0, n - 1);
            break;

        case 4:
            MergeSort(arr, 0, n - 1);
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nSorted array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
/* ---------------- BUBBLE SORT ---------------- */
void BubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/* ---------------- INSERTION SORT ---------------- */
void InsertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
/* ---------------- PARTITION / QUICK SORT ---------------- */
int Partition(int arr[], int low, int high)
{
    int pivot;
    int i, j;
    int temp;

    pivot = arr[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
void QuickSort(int arr[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = Partition(arr, low, high);

        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}
/* ---------------- MERGE SORT ---------------- */
void MergeSort(int arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);

        Merge(arr, low, mid, high);
    }
}

void Merge(int arr[], int low, int mid, int high)
{
    int SA[10];
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            SA[k] = arr[i];
            i++;
        }
        else
        {
            SA[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        SA[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        SA[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = SA[i];
    }
}
