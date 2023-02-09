// CONCLUSONS FOR STACKS (ONLY THE BASIC FUNCTIONS);

#include<stdio.h>
#define N 3

struct student
{
    char data1[30];
    int data2;
    char type;
};

int main()
{
    void display(struct student [], int );
    void push(struct student [], int , struct student p);
    struct student pop(struct student [], int);
    struct student stack[N];
    struct student p;
    struct student d;
    int top=-1;

    char ch;
    struct student p;
    f=-1;
    r=-1;
    while(1)
    {
        printf("1--push?\n");
        printf("2--pop?\n");
        printf("3--display?\n");
        printf("4--isempty?\n");
        printf("5--isfull?\n");
        printf("6--peek?\n");*/
        printf("7--exit?\n");
        printf("enter the choice\n");
        printf("exit\n");

       printf("enter choice\n");
       scanf(" %c",&ch);

       switch(ch)
       {
        case '1': push();
                  break;
        case '2': pop();
                break;
        case '3': d=display();
                if(d!=(-999))
                {
                    printf("student record popped is :\n");
                    printf("name=%s rno=%d\n",);
                }
                top--;
                break;
        case '4': isempty();
                break;
        case '5': isfull();
                break;
        case '6': peek();
                break;
        default:printf("Invalid choice\n");
                break;
       }
    }
}
void push(struct student stack[N], int top, struct student p)
{
    if(top==MAX-1)
    {
        printf("stack is full\n");
    }
    else
    {

        top++;
        stack[top]=p;
    }
}

struct student pop()
{
    if(is_empty(top))
    {
         printf("stack is empty\n");
         return -999;
    }
    else
    {
        return(stack[top]);
    }

}

void display(struct student[N] ,int top)
{
   int i;
   if(is_empty(top))
    {
         printf("stack is empty\n");
         return -999;
    }
   else
   {
       printf("stack records are\n");
      for(i=top;i>=0;i--)
      {
          stack[i];
        printf("name=%s rno=%d gender=%c\n",stack[i].name,stack[i].rno,stack[i].type);

      }
   }
}

void peek(struct student stack[N], int top)
{
    if(is_empty(top))
    {
         printf("stack is empty\n");
    }

    else
    {
        printf("stack records are\n");
        printf("name=%s rno=%d\n",stack[top].name,stack[top].rno);
    }
}


