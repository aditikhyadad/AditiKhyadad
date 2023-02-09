#include<stdio.h>
#define N 5
struct student
{
   char name[30];
   int rank;
   char g;
};
struct student q[N];
void insert();
void del();
void display();
void sort();
int f,r;
main()
{
    char ch;
    struct student p;
    f=-1;
    r=-1;
    while(1)
    {
       printf("1.insert\n");
       printf("2.delete\n");
       printf("3.display\n");
       printf("4.count\n");

       printf("enter choice\n");
       scanf(" %c",&ch);

       switch(ch)
       {
          case '1': insert();
                  break;
        case '2': del();
                break;
        case '3': display();
                break;
        case '4': count();
                break;
        default:printf("Invalid choice\n");
                break;
       }
    }
}
void insert()
{
    if(r==N-1)
    {
        printf("QUEUE FULL\n");
    }
    else
    {
        if(f==-1&&r==-1)
        {
            f++;
            r++;
            printf("ENTER STUDENT NAME RANK GENDER:\n");
            scanf(" %s%d %c",&q[r].name,&q[r].rank,&q[r].g);
        }
        else
        {
            r++;
            printf("ENTER STUDENT NAME RANK GENDER:\n");
            scanf(" %s%d %c",&q[r].name,&q[r].rank,&q[r].g);
        }
        sort();
    }
}
void del()
{
    if(r==-1&&f==-1)
    {
        printf("EMPTY QUEUE\n");
    }
    else
    {
        if(f==r)
        {
            printf("verified student is name= %s rank=%d gender= %c\n",q[f].name,q[f].rank,q[f].g);
            f=-1;
            r=-1;
        }
        else
        {
           printf("verified student is name= %s rank=%d gender= %c\n",q[f].name,q[f].rank,q[f].g);
            f++;
        }
    }
}
void sort()
{
    int i,j;
    struct student temp;
    for(i=0;i<=r;i++)
    {
        for(j=0;j<r-i;j++)

            if(q[j].rank>q[j+1].rank)
            {
                temp=q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
            }
        }
    }
void count()
{
    int c=0;
    int i;
    for(i=0;i<=r;i++)
    {
        c++;
    }
    printf("STUDENTS=%d\n",c);
}
void display()
{
    int i;
    if(f==-1&&r==-1)
    {
        printf("EMPTY QUEUE\n");
    }
    else
    {
        for(i=f;i<=r;i++)
        {
            printf(" name= %s rank=%d gender=%c\n",q[i].name,q[i].rank,q[i].g);
        }
    }
}
