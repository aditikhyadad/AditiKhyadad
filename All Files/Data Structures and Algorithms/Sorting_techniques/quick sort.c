#include <stdio.h>
#include<time.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pivot = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pivot - 1);

        // recursive call on the right of pivot
        quickSort(array, pivot + 1, high);
  }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int a[100000],n;


    printf("Enter the size: ");
    scanf("%d",&n);

    clock_t s_time,e_time;
    s_time=clock();
    printf("Enter values to be sorted:\n ");
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10;
    }
    printArray(a, n);
    quickSort(a, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(a, n);
    e_time=clock();
    double time_taken=((double)(e_time-s_time))/CLOCKS_PER_SEC;
    printf("\n\nTime Taken for merge Sort: %lf",time_taken);
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");
}
