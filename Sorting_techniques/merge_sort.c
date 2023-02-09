#include<stdio.h>

void merge(int a[10],int b[10],int m, int n,int c[10])
{
    int i,j;
    int k=0;
    for(i=0,j=0; i<m,j<n; )
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }

        if(b[j]<a[i])
        {
            c[k]=b[j];
            k++;
            j++;
        }

        while(i<n)
        {
            c[i]=a[i];
            k++;
            i++;
        }

        while(j<m)
        {
            c[j]=b[j];
            k++;
            j++;
        }
    }
    display(c,m+n);
}

void read(int a[10],int b[10],int m,int n)
{
    int i,j;
    printf("Enter the values of the 1st array\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter the values of the 2nd array\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&b[j]);
    }
}

void display(int a[10],int n)
{
    int i,j;
    printf("The values of the 1st array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

}

main()
{
    int a[10],b[10],c[10];
    int m,n;

    printf("Enter the values of m and n\n");
    scanf("%d%d",&m,&n);
    read(a,b,m,n);
    merge(a,b,m,n,c);
    display(c,m+n);
}
