#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int size;
    int top;
    char *p;
};
char pop(struct Stack *st);
void push(struct Stack *st, char ch);
int operandCheck(char ch);
int preCheck(char ch);
char* infixToPostfix(char *infix);
char* infixToPostfix(char *infix)
{
    struct Stack st;
    st.size=strlen(infix);
    cout<<"st.size is"<<st.size<<endl;
    st.top=-1;
    st.p=new char[st.size];
    char* postfix=new char[st.size+2];
    //adding 1 to accomodate NULL.
    int i=0,j=0;
    while(infix[i]!='\0')
    {
       cout<<infix[i]<<endl;
        if(operandCheck(infix[i]))
        {
            postfix[j++]=infix[i++];
             cout<<"adding to postFix..."<<endl;
        }
        else
        {
            cout<<"coming into else"<<endl;
             if(st.top==-1)
            {
             cout<<"going to push"<<endl;
             push(&st,infix[i]);
             cout<<"Successfully pushed"<<endl;
             i++;
            }
             else
             {
             if(preCheck(infix[i])>preCheck(st.p[st.top]))
             push(&st,infix[i++]);
             else 
             postfix[j++]=pop(&st);
             }
        }
    }
    while(st.top!=-1)
    {
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';
    return postfix;
}


int operandCheck(char ch)
{
    cout<<"operandChecking..."<<endl;
    if (ch=='+'||ch=='-'||ch=='*'||ch=='/')
{
    cout<<"operator..."<<endl;
    return 0;
}
    else 
    {
        cout<<"operand"<<endl;
          return 1;
    }
  
}
int preCheck(char ch)
{
      cout<<"precedenceChecking..."<<endl;
      if (ch=='+'||ch=='-')
      return 1;
      else  if (ch=='*'||ch=='/')
      return 2;
      return 0;
}
char pop(struct Stack *st)
{
    char u;
    if(st->top==-1)
    cout<<"STACK UNDERFLOW"<<endl;
    else
    u=st->p[st->top];
    st->top--;
    cout<< st->p[st->top]<<"popped out"<<endl;
    return u;
}
void push(struct Stack *st, char cha)
{
    cout<<"Entered into push func"<<endl;
    st->top++;
    cout<<"Incrementing top"<<endl;
    cout<<"value of top now is "<<st->top<<endl;
    cout<<"Value of ch is "<<cha<<endl;
    st->p[st->top]=cha;
    cout<<"Assigned ch to top"<<endl;
    cout<<st->p[st->top]<<"pushed in stack"<<endl;
}
int main() {
     char str[]="a+b*c-d/e";
    cout<<infixToPostfix(str);
    return 0;
}