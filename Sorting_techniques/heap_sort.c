#include <stdio.h>

void read(int a[10],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        //scanf("%d",&a[i]);
        a[i]=rand()%20;
    }
}

void display(int a[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    int i;
    for(i=n/2-1; i>=0; i--)
    {
        heapify(a, n, i);
    }

    for(i=n-1; i>=0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a,i,0);
    }
}

void swap(int* a, int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

main()
{
    int a[20];
    int n;

    printf("Enter the value of n\n");
    scanf("%d",&n);

    read(a,n);
    printf("Before sorting the elements are:\n");
    display(a,n);
    printf("\n");
    heap_sort(a,n);
    printf("After sorting the elements are:\n");
    display(a, n);
}

