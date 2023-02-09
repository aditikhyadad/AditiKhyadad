#include<stdio.h>
#include<stdlib.h>
main()
{
    int mx;
    int a[10];
    int n;
    scanf("%d",&n);

    read(a,n);
    display(a,n);
    selection(a,n);
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

int max(int a[10],int n)
{
    int mx=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]>a[mx])
        {
            mx=i;
        }
    }
    return mx;
}

void selection(int a[10],int n)
{
    int mx;
    int i,temp;
    for(i=0;i<n;i++)
    {
        mx=max(a,n-i);

        //swap(a[n-i-1],mx);
        temp=a[n-i-1];
        a[n-i-1]=a[mx];
        a[mx]=temp;

    }
}
