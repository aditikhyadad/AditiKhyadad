#include<stdio.h>
#define N 5

struct student
{
    char name[30];
    int rank;
    char gender;
};

struct student queue[N];
void enqueue(struct student);
struct student dequeue();
void display();
void sort();
int count_fun();
int f,r;

int main()
{
    struct student s;
    struct student d;
    f=-1;
    r=-1;
    int ch,c;
    while(1)
    {
        printf("1.Enqueue?\n");
        printf("2.Dequeue?\n");
        printf("3.Display\n");
        printf("4.Count?\n");
        printf("5.Exit?\n");
        printf("enter choice\n");
        scanf("%d",&ch);

        switch(ch)
       {
          case 1: if(r==N-1)
              {
                 printf("QUEUE FULL\n");
              }
              else
              {
                printf("enter student name, rank and the gender(female/male):\n");
                scanf("%s%d%*c%c",&s.name,&s.rank,&s.gender);
                enqueue(s);
              }
                sort();
                break;

        case 2: if(f==-1 && r==-1)
                {
                   printf("EMPTY QUEUE\n");
                }
                else
                {
                 d=dequeue();
                 printf("STUDENT DETAILS\t name=%s\t rank=%d\t gender=%c\n",d.name,d.rank,d.gender);
                }
                break;

        case 3: display();
                break;

        case 4: c=count_fun;
                printf("count=%d",c);
                break;

        case 5:exit(0);
               break;

        default:printf("Invalid choice\n");
               break;
       }


    }


}

void enqueue(struct student s)
{
    if(f==-1 && r==-1)
    {
        f=0;
        r=0;
        queue[r]=s;
    }
    else
    {
        r++;
        queue[r]=s;
    }
}

struct student dequeue()
{
    struct student a;
    if(f==r)
    {
        a=queue[f];
        f=-1;
        r=-1;
    }
    else
    {
        a=queue[f];
        f++;
    }
    return a;
}
 void display()
{
    if(f==-1 && r==-1)
    {
        printf("empty\n");
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
         printf("STUDENT DETAILS\t name=%s\t rank=%d\t gender=%c\n",queue[i].name,queue[i].rank,queue[i].gender);
        }
    }

}


int count_fun()
{
    int i,c=0;
    if(f==-1 && r==-1)
    {
        printf("EMPTY QUEUE\n");
    }
    else
    {
        for(i=f ;i<=r ;i++)
        {
            c++;
        }
    }
}

void sort()
{
    int i,j;
    struct student temp;
    for (i=0; i<=(r-f+1); i++)
    {
        for (j=0; j<=(r-f+1)-i-1 ; j++)
            {
                if(queue[j].rank>queue[j+1].rank)
                {
                    temp=queue[j];
                    queue[j]=queue[j+1];
                    queue[j+1]=temp;
                }
            }
    }

}
