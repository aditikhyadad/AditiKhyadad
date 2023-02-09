#include<stdio.h>
#include<time.h>

void read(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%20;
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void merge(int a[], int mid, int low, int high)
{
    int i,j,k,b[100000];
    i=low;
    j=mid + 1;
    k=low;

    while(i<=mid && j<=high)
    {
        if (a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while (i<=mid)
    {
        b[k++]=a[i++];
    }
    while (j<=high)
    {
        b[k++]=a[j++];
    }
    for (int i=low; i<=high; i++)
    {
        a[i]=b[i];
    }
}

void mergeSort(int a[], int low, int high){
    int mid;
    if(low<high)
    {
        mid = (low + high) /2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int a[100000];
    int n;

    printf("Enter the size: ");
    scanf("%d",&n);
    clock_t s_time,e_time;

    s_time=clock();

        printf("Enter Numbers: ");
        read(a,n);
        display(a, n);

        mergeSort(a, 0, n-1);
        printf("Sorted array is: ");
        display(a, n);

    e_time=clock();

    double time_taken=((double)(e_time-s_time))/CLOCKS_PER_SEC;
    printf("\n\nTime Taken for merge Sort: %lf",time_taken);
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");

}

