#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 10

struct  patient
{
    int id;
    char n[30];    // name
    char s[30];    // source
    char d[30];    // destination
    int w;         // weight
};

main()
{
int f,r;
int *fptr,*rptr;
fptr=&f;
rptr=&r;
struct patient p;
struct patient queue[max];
void insert(struct patient [],int *,int *,struct patient);
void display(struct patient [],int *,int *);
void sort(struct patient [],int * ,int *);

    f=-1;
    r=-1;

int n,i;
    scanf("%d",&n);
    printf("%d",n);

   for(i=1; i<=n; i++)
   {
       scanf("%d%s%s%s%d",&p.id,&p.n,&p.s,&p.d,&p.w);
       if(queue[max].w >=0 && queue[max].w <=30)
       {
           insert(queue,fptr,rptr,p);
           sort(queue,fptr,rptr);
       }

       else
       {
          exit(0);
       }
   }
  display(queue,fptr,rptr);

}

void insert(struct patient queue[max],int *fptr,int *rptr,struct patient p)
{

 if(*rptr==max-1)
    {
        printf("QUEUE FULL\n");
    }
    else
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


}

void display(struct patient queue[max],int *fptr,int *rptr)
{
    if(*fptr==-1 && *rptr==-1)
    {
        ;
    }
    else
    {
        for(int i=*fptr;i<=*rptr;i++)
        {
              printf("%d %s %s %s %d\n",queue[i].id,queue[i].n,queue[i].s,queue[i].d,queue[i].w);
        }
    }

}



void sort(struct patient queue[max],int *fptr,int *rptr)
{   /*a=a+b;//a=30 (10+20)
    b=a-b;//b=10 (30-20)
    a=a-b;//a=20 (30-10)*/

    int i,j;
    struct patient temp;
    for (i=*fptr; i<=(*rptr-*fptr+1); i++)
    {
        for (j=*fptr; j<=(*rptr-*fptr+1)-i-1 ; j++)
            {
                if(queue[j].w < queue[j+1].w)
                {
                   /* queue[j] = queue[j]+(queue[j]+1);
                    queue[j+1] =queue[j]-queue[j+1];
                    queue[j] = queue[j] - queue[j+1];*/

                    temp=queue[j];
                    queue[j]=queue[j+1];
                    queue[j+1]=temp;
                }
            }
    }

}

// CONCLUSIONS TO THE STACKS
