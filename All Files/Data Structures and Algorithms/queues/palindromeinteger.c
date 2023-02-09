#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct stack
{
    int st[100];
    int top;
};
void push(struct stack *s,int);
int pop(struct stack *s);
int check(struct stack *s);
int main()
{
   int n,r,t;
    struct stack stk;
    struct stack *s;
    s=&stk;
    s->top=-1;
    scanf("%d",&n);
    if(n<0)
    {
        printf("Invalid number");
        exit(0);
    }
    t=n;
    while(n)
    {
        r=n%10;
        push(s,r);
        n=n/10;
    }
    int d=check(s);
    if(d==1)
        printf("%d is a palindrome number",t);
    else
        printf("%d is not a palindrome number",t);
}
void push(struct stack *s,int n)
{
    s->top++;
    s->st[s->top]=n;
}
int pop(struct stack *s)
{
    return(s->st[s->top]);
}
int check(struct stack *s)
{
    int i;
    int flag=1;
    for(i=0;s->top!=-1;i++)
    {
        if(s->st[i]!=pop(s))
            flag=0;
        s->top--;
    }
    return(flag);
}
