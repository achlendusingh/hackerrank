#include <iostream>
using namespace std;
struct Queue 
{
    int size;
    int front;
    int rear;
    int *Q;
};


void enqueue(struct Queue *q,int x);
void create(int x);
void dequeue(struct Queue *q);


void create(struct Queue *q,int x)
{
    q->size=x;
    q->Q=(int*)malloc(q->size*sizeof(int));
    q->front=-1;
    q->rear=-1;
    cout<<"QUEUE CREATED SUCCESSFULLY"<<endl;
};

void enqueue(struct Queue *q,int x)
{
    cout<<"Enqueueing "<<x<<"..."<<endl;
    if(q->rear==q->size-1)
    cout<<"Queue is Full->Enqueue failed."<<endl;
    else 
    {
        
        q->rear++;
        q->Q[q->rear]=x;
        cout<<x<<" enqueued successfully"<<endl;
        cout<<"Value of rear is "<<q->rear<<endl;
    }
}
void dequeue(struct Queue *q)
{
    int x;
    cout<<"Value of front is "<<q->front<<endl;
    cout<<"Value of rear is "<<q->rear<<endl;
    if(q->front==q->rear)
    {
       cout<<"Cannot dequeue beacuse queue is empty"<<endl; 
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
        cout<<x<<" dequeued successfully"<<endl;
    }
}
int main() {
    // Write C++ code here
    int si;
    cout<<"Enter the size of the queue-";
    cin>>si;
    struct Queue q;
    create(&q,si);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    dequeue(&q);
    dequeue(&q);
    return 0;
}