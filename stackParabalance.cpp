#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void push(struct Stack *st, char ch);
bool isBalanced(char*(exp));
void pop(struct Stack *st);
struct Stack{
        int size;
        int top;
        char* p;
    };
bool isBalanced(char*(exp))
{
    struct Stack st;
    st.size=strlen(exp);   //strlen is used to find length of strings only, whereas sizeOf operator ca find the size of any data type.
    st.top=-1;
    st.p=new char[st.size];
    for (int i=0;exp[i]!='\0';i++)
    {
        cout<<exp[i]<<endl;
        if (exp[i]=='(')
        {
            push(&st,'(');
            cout<<"The value top is "<<st.top<<endl;
        }
        if (exp[i]==')')
        {
            // if(st.top==-1)
            if(st.top==-1)
            return false;
            pop(&st);
            cout<<"The value top is "<<st.top<<endl;
        }
    }
    if(st.top==-1)
        return true;
        else
        return false;
}
void push(struct Stack *st, char ch)
{
    st->top++;
    st->p[st->top]=ch;
    cout<<"pushed"<<endl;
}
void pop(struct Stack *st)
{
    if(st->top==-1)
    cout<<"Stack empty"<<endl;
    st->top--;
    cout<<"popped"<<endl;
}
int main() {
    char tu[]="helloworld(((()))";  //char*tu="string" wont work. but can use const char *tu="string" in C++.
    char *str=&tu[0];  
    cout<<isBalanced(str)<<endl;

    return 0;
}

