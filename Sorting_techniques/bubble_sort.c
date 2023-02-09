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
    bubble(a,n);
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

void bubble(int a[10],int n)
{
    int i,j;
    int temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {

                temp=a[j];
                a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
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
