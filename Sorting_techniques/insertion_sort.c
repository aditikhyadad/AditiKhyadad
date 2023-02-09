#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
    int mx;
    int a[10];
    int n;
    printf("Enter the values of the array to be inserted\n");
    scanf("%d",&n);

    read(a,n);
    display(a,n);
    insertion(a,n);
    display(a,n);
}


void read(int a[10], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void display(int a[10], int n)
{
    int i;
    printf("elements of the array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

void insertion(int a[10],int n)
{
    int i,j,key;
    for(i=0;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }

        a[j+1]=key;
    }
}

