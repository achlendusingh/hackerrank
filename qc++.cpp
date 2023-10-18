#include<iostream>
using namespace std;

class Queue{
    public:
    int size;
    int front;
    int rear;
    int *q;
    // Queue()
    // {
    //   front=rear=-1;
    //   size=10;
    //   q=new int[size];
    // }
    Queue(int size)
    {
       front=rear=-1;
       this->size=size;
       q=new int[this->size];
    }
    void enqueue(int x)
    {
        if (rear==size-1)
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            rear++;
            q[rear]=x;
            cout<<x<<" enqueued successfully"<<endl;
        }
    }
    void dequeue()
    {
        int x;
        if(front==rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
              front++;
            x=q[front];
            cout<<x<<" dequeued successfully"<<endl;
        }
    }
    void display()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<q[i]<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    Queue t(5);
    t.enqueue(1);
    t.enqueue(2);
    t.enqueue(3);
    t.enqueue(4);
    t.enqueue(5);
    t.display();
    t.dequeue();
    t.dequeue();
    t.dequeue();
    t.display();
    return 0;
}