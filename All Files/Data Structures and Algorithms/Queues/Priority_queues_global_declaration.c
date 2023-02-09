// PATIENT EXAMPLE BY SIR WITH GLOABAL DECLARATION.

#include<stdio.h>
#define max 5
struct patient
{
   char name[30];
   int priority;
};
struct patient queue[max];
void insert(struct patient);
struct patient delete();
void display();
void sort();
int f,r;
main()
{
    int ch,ele;
    struct patient p;
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
          case 1: if(r==max-1)
                    printf("priority queue is full\n");
                  else
                  {
                      printf("enter patient name and priority\n");
                      scanf("%s%d",&p.name,&p.priority);
                      insert(p);
                  }
                  break;
        case 2: if(f==-1 && r==-1)
                {
                    printf("priority queue is empty\n");
                }
                else
                {
                 p=delete();
                 printf("patient checked\t name=%s\t priority=%d\n",p.name,p.priority);
                }
                break;
        case 3: display();break;
        case 4: exit(0);break;
        default:printf("Invalid choice\n");break;
       }
    }
}

void insert(struct patient p)
{
    if(f==-1 && r==-1)
    {
        f++;
        r++;
        queue[r]=p;
    }
    else
    {
        r++;
        queue[r]=p;
        sort();
    }

}
void sort()
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
    struct patient p;
    if(f==r)
    {
        p=queue[f];
        f=-1;
        r=-1;
        return(p);
    }
    else
    {
      p=queue[f];
        f++;
        return(p);
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

