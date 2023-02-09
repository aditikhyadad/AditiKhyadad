// CIRCULAR QUEUE BY ADITI.

#include<stdio.h>
#define N 5
int queue[N];
int front =-1;
int rear=-1;
void enqueue(int);
int dequeue();
void display();
main()
{
    int ch,ele,s,c;
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
        if((rear+1)%N==front)
        {
            printf("Queue is full,cant append\n");

        }
        else
        {
           printf("Enter element\n");
        scanf("%d",&ele);
        enqueue(ele);
        }

            break;
            case 2: if(front==-1 && rear==-1)
                  printf("Q is EMPTY\n");
                  else
                    s=dequeue();
                    printf("ele deleted=%d\n",s);
                    break;
                    case 3: if(front==-1 && rear==-1)
                     printf("no elements to display\n");
                     else
                        display();
                        break;
                        case 4: c=peek();
                        printf("peek=%d\n",c);
                        break;
                        case 5: exit(0);
                        break;
                        default : printf("Invalid choice\n");

        }

    }
}
void enqueue(int ele)
{
    if(front==-1 && rear==-1)
    {

        front=(front+1)%N;
        rear=(rear+1)%N;
        queue[rear]=ele;

    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=ele;
    }
}
int dequeue()
{
    int g;
    if(front==rear)
    {
        g=queue[front];
        front =-1;
        rear=-1;
    }
    else
    {
        g=queue[front];
        front=(front+1)%N;
    }
    return g;
}
void display()
{
    int i;
    for(i=front;i!=rear;i=(i+1)%N)
    {
        printf("%d\n",queue[i]);
    }
    printf("%d\n",queue[rear]);

}
int peek()
{
    int s;
    s=queue[front];
    return s;
}

