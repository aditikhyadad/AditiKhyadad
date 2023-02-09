// CIRCULAR QUEUE USING STRUCTURES BY ADITI.

#include<stdio.h>
#define N 5

struct student
{
    char name[30];
    int rno;
};

void enqueue(struct student ele);
struct student dequeue();
struct student peek();
void display();

struct student queue[N];
int front =-1;
int rear=-1;

main()
{
    struct student s;
    struct student d,p,ele;
    int ch;
    while(1)
    {
        printf("1.Enqueue?\n");
        printf("2.Dequeue?\n");
        printf("3.Display\n");
        printf("4.Peek?\n");
        printf("5.Exit?\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
        if(rear==N-1)
        {
            printf("Queue is full,cant append\n");
        }
        else
        {
            printf("enter student name and the roll number of the student:\n");
            scanf("%s%d",&s.name,&s.rno);
            enqueue(s);
        }

            break;
            case 2: if(front==-1 && rear==-1)
                  printf("Q is EMPTY\n");
                  else
                    d=dequeue();
                    printf("ele deleted=%d\n",d);
                    break;
                    case 3: if(front==-1 && rear==-1)
                     printf("no elements to display\n");
                     else
                        display();
                        break;
                        case 4: p=peek();
                        printf("peek=%d\n",p);
                        break;
                        case 5: exit(0);
                        break;
                        default : printf("Invalid choice\n");

        }

    }
}
void enqueue(struct student ele)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=ele;
    }
    else
    {
        rear++;
        queue[rear]=ele;
    }
}
struct student dequeue()
{
    struct student g;
    if(front==rear)
    {
        g=queue[front];
        front =-1;
        rear=-1;
    }
    else
    {
        g=queue[front];
        front++;
    }
    return g;
}
void display()
{
    int i;
    printf("stack records are\n");
    for(i=front ;i<rear+1 ;i++)
    {
        printf("name=%s rno=%d\n",queue[i].name,queue[i].rno);
    }

}

struct student peek()
{
    struct student p;
    p=queue[front];
    return p;
}

