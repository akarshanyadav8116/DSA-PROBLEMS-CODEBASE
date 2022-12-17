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

        void insertAtEnd(int v)
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

        void DeleteAtFront()
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

        void deleteAtEnd()
        {
            if(rear == -1)
                cout<<"Underflow"<<endl;
            else if(rear == front)
            {
                cout<<q[rear]<<" deleted"<<endl;
                front = rear = -1;
            }
            else{
                cout<<q[rear--]<<" deleted"<<endl;
            }
        }

        void insertAtBegin(int v)
        {
            if(front == -1)
            {
                front++; rear++;
                q[front] = v;
            }
            else if(rear == size-1)
            {
                cout<<"Overflow"<<endl;
            }
            else{
                    for(int i=rear; i>= front; i--)
                        q[i+1] = q[i];

                    rear++;
                    q[front] = v;
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
    q.insertAtEnd(5);
    q.insertAtEnd(10);
    q.insertAtEnd(15);
    q.insertAtBegin(50);
    q.insertAtBegin(100);
    q.DeleteAtFront();
    q.deleteAtEnd();
    q.insertAtEnd(100);
    q.DeleteAtFront();
    q.deleteAtEnd();
    q.DeleteAtFront();
    q.DeleteAtFront();
    q.deleteAtEnd();
    q.print();

    return 0;
}
