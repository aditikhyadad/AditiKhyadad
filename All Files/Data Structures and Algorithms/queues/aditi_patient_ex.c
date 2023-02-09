// PATIENT EXAMPLE BY SIR WITH GLOABAL DECLARATION.

#include<stdio.h>
#define N 5
struct node
{
   int data;
   int priority;
};

void insert(struct node);
struct node delete();
void display();
void sort();
int f,r;
main()
{
    int ch,ele,d;
    struct patient n;
    struct node queue[N];             // n=node and not number of nodes.
    f=-1;
    r=-1;
    while(1)
    {
       printf("1--insert\n");
       printf("2--delete\n");
       printf("3--display\n");
       printf("4--exit\n");

       printf("enter choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
          case 1: if(r==N-1)
                    printf("priority queue is full\n");
                  else
                  {
                      printf("enter patient name and priority\n");
                      scanf("%s%d",&n.name,&n.priority);
                      insert(queue,f,r,n);
                  }
                  break;
        case 2: if(f==-1 && r==-1)
                {
                    printf("priority queue is empty\n");
                }
                else
                {
                 d=delete(queue,f,r,n);
                 printf("patient checked\t name=%s\t priority=%d\n",d.name,d.priority);
                }
                break;
        case 3: display();break;
        case 4: exit(0);break;
        default:printf("Invalid choice\n");break;
       }
    }
}

void insert(struct node n, int f, int r)
{
    if(f==-1 && r==-1)
    {
        f++;
        r++;
        queue[r]=n;
    }
    else
    {
        r++;
        queue[r]=n;
        sort(queue,f,r,n);
    }

}
void sort(struct node queue[N], int f, int r, struct node n)
{
    int i,j;
    struct patient temp;
    //printf("hi\n");
    for(i=0;i<=r;i++)
    {
        for(j=0;j<=r-i-1;j++)
            {
                if(queue[j].priority<queue[j+1].priority)
                {
                    temp=queue[j];
                    queue[j]=queue[j+1];
                    queue[j+1]=temp;
                }
            }
    }

}

struct patient delete()
{
    struct patient deldata;
    if(f==r)
    {
        deldata=queue[f];
        f=-1;
        r=-1;
        return(deldata);
    }
    else
    {
      deldata=queue[f];
        f++;
        return(deldata);
    }

}

void display()
{
    if(f==-1 && r==-1)
    {
        printf("priority queue is empty\n");
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("name=%s\t priority=%d\n",queue[i].name,queue[i].priority);
        }
    }

}
