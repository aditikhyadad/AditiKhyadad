// PATIENT EXAMPLE BY ADITI WITH LOCAL DECLARATION.

// DIFFERENCE BETWEEN LINEAR AND CIRCULAR QUEUES.
// QUEUE FULL CONDITION.(rear+1)%N==front
// f++:        front=(front+1)%N;
// r++:        rear=(rear+1)%N; //*rptr=((*rptr)+1)
// DISPLAY CONDITION for(i=front; ii!=rear; i=(i+1)%N

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
    f=-1;
    r=-1;
int n,i;
printf("Enter the value of n\n");
scanf("%d",&n);

for(i=1; i<=n; i++)
{
    printf("enter patient name and priority\n");
    scanf("%s%d",&p.name,&p.priority);
    insert(queue,fptr,rptr,p);
}

  p=delete(queue,fptr,rptr);
  printf("\nPatient checked\n");
  printf("name=%s\t priority=%d\n",p.name,p.priority);

  printf("\nThe details of the patients in the hospital:\n");
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

struct patient delete(struct patient queue[max],int *fptr,int *rptr)
{

    struct patient p;
    if((*rptr)==-1&&(*fptr)==-1)
    {
        printf("EMPTY QUEUE\n");
    }
    else
    {
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
