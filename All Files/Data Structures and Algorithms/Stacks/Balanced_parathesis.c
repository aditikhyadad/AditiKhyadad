#include<stdio.h>
#define max 30
void push(char c);
char pop();
void bal_par_exp(char expression[max]);
char stack[max];
top=-1;

main()
{
char expression[max];
printf("enter a expression\n");
scanf("%s",expression);
bal_par_exp(expression);
}


void push(char c)
{
   if(top!=max-1)
   {
       top++;
       stack[top]=c;
   }
}

char pop()
{
    char sym;
    if(top!=-1)
    {

    sym=stack[top];
    top--;
    return(sym);
    }
}

void bal_par_exp(char expression[max])
{
   int i=0,status=1;
   char sym1,sym2;
   while(expression[i]!='\0')
   {
       sym1=expression[i];
       if(sym1=='('||sym1=='{'||sym1=='[')
            {
                push(sym1);
            }

      if(sym1==')'||sym1=='}'||sym1==']')
      {
          sym2=pop();
          if(sym1==')')
          {
                if(sym2!='(')
                {
                    status=0;
                    break;
                }
          }
          else if(sym1=='}')
            {
                 if(sym2!='{')
                {
                    status=0;
                    break;
                }

            }

             else if(sym1==']')
            {
                 if(sym2!='[')
                {
                    status=0;
                    break;
                }

            }


      }
      i++;
   }
   if(top==-1)
   {
       if(status==1)
    printf("it is balanced paranthesis expression\n");
   else
    printf("it is not balanced paranthesis expression\n");
   }
   else
   {
       printf("it is not balanced paranthesis expression\n");
   }

}

