#include<iostream>
using namespace std;

class Queue
{
        int q[100];
        int front;
        int rear;
        int size;

    public :

        Queue()
        {
            front = -1;
            rear = -1;
            size =  100;
        }

        void Enqueue(int v)
        {
            if(rear == -1)
            {
                rear++;
                front++;
                q[rear] = v;
            }
            else if(rear == size-1)
            {
                cout<<"Overflow"<<endl;
            }
            else
            {
                q[++rear] = v;
            }
        }

        void Dequeue()
        {
            if(front == -1)
                cout<<"Underflow"<<endl;
            else if(rear == front)
            {
                cout<<q[front]<<" deleted"<<endl;
                front = rear = -1;
            }
            else{
                cout<<q[front++]<<" deleted"<<endl;
            }
        }

        void print()
        {
            if(front == -1)
            {
                cout<<"Queue is Empty"<<endl;
                return;
            }
            for(int i= front ; i<= rear ;i++)
                cout<<q[i]<<" ";
            cout<<endl;
        }
};

int main()
{
    Queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.print();
    q.Dequeue();
    q.print();
    q.Dequeue();
    q.print();
    q.Dequeue();
    q.print();
    return 0;
}
