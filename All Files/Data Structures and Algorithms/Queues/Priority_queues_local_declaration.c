// PATIENT EXAMPLE BY ADITI WITH LOCAL DECLARATION.

#include<stdio.h>
#include<stdlib.h>
#define max 5
struct patient
{
   char name[30];
   int priority;
};

main()
{
int f,r;
int *fptr,*rptr;
fptr=&f;
rptr=&r;
int ch,ele;
struct patient p;
struct patient queue[max];
void insert(struct patient [],int *,int *,struct patient);
struct patient delete(struct patient [],int *,int *);
void display(struct patient [],int *,int *);
void sort(struct patient [],int *,int *);
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
                      insert(queue,fptr,rptr,p);
                  }
                  sort(queue,fptr,rptr);
                  break;
        case 2: if(f==-1 && r==-1)
                {
                    printf("priority queue is empty\n");
                }
                else
                {
                 p=delete(queue,fptr,rptr);
                 printf("patient checked\t name=%s\t priority=%d\n",p.name,p.priority);
                }
                break;
        case 3: display(queue,fptr,rptr);break;
        case 4: exit(0);break;
        default:printf("Invalid choice\n");break;
       }
    }
}

void insert(struct patient queue[max],int *fptr,int *rptr,struct patient p)
{

    if((*fptr==-1) && (*rptr==-1))
    {
        *fptr=*fptr+1;
        *rptr=*rptr+1;
        queue[*rptr]=p;
    }
    else
    {
      *rptr=*rptr+1;
        queue[*rptr]=p;

    }

}
void sort(struct patient queue[max],int *fptr,int *rptr)
{
    int i,j;
    struct patient temp;
    for(i=0;i<=*rptr;i++)
    {
        for(j=0;j<=*rptr-i-1;j++)
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

struct patient delete(struct patient queue[max],int *fptr,int *rptr)
{
    struct patient p;
    if(*fptr==*rptr)
    {
        p=queue[*fptr];
        *fptr=-1;
        *rptr=-1;
        return(p);
    }
    else
    {
      p=queue[*fptr];
        *fptr=*fptr+1;
        return(p);
    }

}

void display(struct patient queue[max],int *fptr,int *rptr)
{
    if(*fptr==-1 && *rptr==-1)
    {
        printf("priority queue is empty\n");
    }
    else
    {
        for(int i=*fptr;i<=*rptr;i++)
        {
            printf("name=%s\t priority=%d\n",queue[i].name,queue[i].priority);
        }
    }

}

