#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int size;
    int top;
    int *S;
};
void create(struct Stack *st)
{
   printf("Enter the size of the stack yyou want to create");
   scanf("%d",&st->size);
   st->top=-1;
   st->S=(int *)malloc(st->size*sizeof(int));
}

void push(struct Stack *st, int x)
{
   if(st->top==st->size-1)
   {
    printf("STACK OVERFLOW");
   }
   else
   {
     st->top++;
     st->S[st->top]=x;
   }
}

void display(struct Stack st)
{
    printf("Now displaying the stack");
    for(int i=0;i<=st.top;i++)
    {
        printf("%d\n",st.S[i]);
    }
}

int pop(struct Stack *st)
{
  int t=-1;
  if(st->top==-1)
  printf("STACK UNDERFLOW\n");
  else{
       t=st->S[st->top];
       (st->top)--;
  }
  return t;
}

int peek(struct Stack st, int pos){
    if(st.top==-1)
  printf("STACK UNDERFLOW\n");
  else
  printf("%d\n",st.S[st.top-pos+1]);
}

int main()
{
    struct Stack st;
    char c='Y';
   do{
     printf("MENU\n");
    printf("Create a Stack->1\n");
    printf("Display the Stack->2\n");
    printf("Insert into Stack->3\n");
    printf("Delete from Stack->4\n");
    printf("Peek into the Stack->5\n");
    printf("End->6\n");
    printf("Enter your choice below");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: 
                create(&st);
                break;
        case 2:
                display(st);
                break;
        case 3:
                printf("Enter the element you want to push inside the stack\n");
                int n;
                scanf("%d",&n);
                push(&st,n);
                break;
        case 4:
               int t=pop(&st);
               printf("The popped element is %d\n",t);
               break;
        case 5:
               printf("Enter the position you want to peek at inside the stack\n");
                int p;
                scanf("%d",&p);
                int k=peek(st,p);
                printf("The element is %d\n",k);
                break;
        case 6: 
               c='n'; 
                break;
        default: 
        printf("Wrong choice. Enter again");
    }
   }while(c=='Y');
   return 0;
}