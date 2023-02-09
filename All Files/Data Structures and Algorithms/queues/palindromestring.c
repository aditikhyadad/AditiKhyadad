#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct stack
{
    char st[100];
    int top;
};
void push(struct stack *s,char);
char pop(struct stack*);
int main()
{
    char str[100];
    struct stack stk;
    struct stack *s;
    s=&stk;
    s->top=-1;
    int i, count = 0, len;
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        push(s,str[i]);
    }
    for (i = 0; i < len; i++)
    {
        if (str[i] == pop(s))
            count++;
    }
    if (count == len)
    printf("%s is a palindrome string\n", str);
    else
    printf("%s is not a palindrome string\n", str);
    return(0);
}
/* Function to push character into stack */
void push(struct stack *s,char c)
{
    s->top++;
    s->st[s->top] = c;
}
/* Function to pop the top character from stack */
char pop(struct stack *s)
{
    return(s->st[s->top--]);
}
