#include<stdio.h>
#define max 30
float stack[max];
int top=-1;
void push(float);
float pop();
void eval_postfix(char[]);
int is_operator(char);
main()
{
    char postfix[max];
    printf("enter a valid postfix exp\n");
    gets(postfix);
    eval_postfix(postfix);
}

int is_operator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
        return(1);
    else
        return(0);
}

 void push(float val)
{
    if(top!=29)
    {
        top=top+1;
        stack[top]=val;
    }
}

float  pop()
{
float val;
    if(top!=-1)
    {
       val=stack[top];
       top--;
       return(val);
    }
}

void eval_postfix(char postfix[max])
{
   float  res,num1,num2,val;
   int i=0;
   char sym;
   while(postfix[i]!='\0')
   {
   sym=postfix[i];
   if(isalpha(sym))
   {
       printf("enter the value of %c\n",sym);
       scanf("%f",&val);
       push(val);
   }

   else if(is_operator(sym))
   {
       num2=pop();
       num1=pop();
       switch(sym)
       {
          case '+': res=num1+num2;
                             push(res);
                             break;
        case '-': res=num1-num2;
                             push(res);
                             break;
       case '*': res=num1*num2;
                             push(res);
                             break;
        case '/':res=(float)num1/num2;
                             push(res);
                             break;

       }
   }

    i++;
   }

   res=pop();
   printf("the result of postfix evaluation=%f\n",res);
}

