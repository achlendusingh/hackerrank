#include <iostream>
using namespace std;
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q,int x)
{
    q->front=q->rear=0;
    q->size=x;
    q->Q=new int[q->size];
}
void enqueue(struct Queue *q,int x)
{
    cout<<"starting enqueue..., ";
     cout<<"value of q->rear is"<<q->rear<<", ";
         cout<<"value of q->front is"<<q->front<<endl;
    if (((q->rear+1)%q->size)==q->front)
    {
        cout<<"Queue is full"<<endl;
        cout<<"value of q->rear is"<<q->rear;
         cout<<"value of q->front is"<<q->front<<endl;
    }
    else
    {
        q->rear=(((q->rear)+1)%q->size);
        q->Q[q->rear]=x;
        cout<<x<<" enqueued successfully, ";
        cout<<"value of q->rear is"<<q->rear<<", ";
         cout<<"value of q->front is"<<q->front<<endl;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    cout<<"Queue is empty"<<endl;
    else
    {
        q->front=(((q->front)+1)%q->size);
        x=q->Q[q->front];
    }
    return x;
}

int main() {
    // Write C++ code here
   struct Queue q;
   cout<<"Enter the size of the queue"<<endl;
   int s;
   cin>>s;
   create(&q,s);
   enqueue(&q,1);
   enqueue(&q,2);
   enqueue(&q,3);
   enqueue(&q,4);
   cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
   cout<<dequeue(&q)<<endl;
  cout<<dequeue(&q)<<endl;
  cout<<dequeue(&q)<<endl;
    return 0;
}