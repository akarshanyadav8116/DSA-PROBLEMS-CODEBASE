#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
    public:

    int value;
    node * next;

    node()
    {
        value = 0;
        next = NULL;
    }
};

class LinkedList
{
    node *head;

    public:

        LinkedList()
        {
            head = NULL;
        }

        void insertAtEnd(int v)
        {
            node *temp = new node();
            temp->value = v;
            // for first node
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                node *t = head;
                //move to the last node
                while(t->next != NULL)
                {
                    t = t->next;
                }
                t->next = temp;
            }
        }

        void insertAtBegin(int v)
        {
            node *temp = new node();
            temp->value = v;

            if(head == NULL)
            {
                head = temp;
            }
            else{
                temp->next = head;
                head = temp;
            }
        }

        void insertInMiddle(int v, int n)
        {
            node *temp = new node();
            temp->value = v;

            if(n == 1)
            {
                temp->next = head;
                head = temp;
            }else{
                node *t = head;
                while(n>1)
                {
                    n--;
                    if(t->next != NULL)
                    {
                        t = t->next;
                    }else
                    {
                     cout<<"Position does not exist"<<endl;
                     return ;
                    }
                }
                    temp->next = t->next;
                    t->next = temp;
            }
        }

        void printLL()
        {
            node *t = head;
            while(t != NULL)
            {
                cout<<t->value<<" -> ";
                t = t->next;
            }
            cout<<endl<<endl;
        }

        void deleteAtMiddle(int n)
        {
            node *temp = head;
            if(n==1)
            {
                head = head->next;
                cout<<temp->value<<" deleted"<<endl;
                delete temp;
            }else{
                  while(n > 2)
                  {
                     n--;

                     if(temp->next->next != NULL)
                         temp = temp->next;
                    else{
                        cout<<"Position does not exist"<<endl;
                        return;
                      }
                  }
                  node * t = temp->next;
                  temp->next = t->next;
                  cout<<t->value<<" deleted"<<endl;
                  delete t;

            }

        }

        void search(int v)
        {
            node *temp = head;

            if(head == NULL)
            {
                cout<<"Linked List is Empty"<<endl;
            }
            else{
                int count = 0;
                while(temp != NULL)
                {   count++;
                    if(temp->value == v)
                    {
                        cout<<"Value Found at "<<count<<endl;
                        return;
                    }
                    temp = temp->next;
                }
                cout<<"Element Not Found"<<endl;
            }
        }

};
int main()
{
    LinkedList ll;
    int choice;

    while(1)
    {
    cout<<endl<<endl<<"================================================"<<endl<<endl;
    cout<<"1. Insert at Begin"<<endl;
    cout<<"2. Insert at Middle"<<endl;
    cout<<"3. Insert at the End"<<endl;
    cout<<"4. Delete at the which Position"<<endl;
    cout<<"5. Search"<<endl;
    cout<<"6. Print"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"Enter Your choice"<<endl;
    cin>>choice;
    int value,position;
    switch(choice)
    {
        case 1 :
                cout<<"Enter value"<<endl;
                cin>>value;
                ll.insertAtBegin(value);
                break;
        case 2:
                cout<<"Enter value and position"<<endl;
                cin>>value>>position;
                ll.insertInMiddle(value,position);
                break;
        case 3:
                cout<<"Enter value"<<endl;
                cin>>value;
                ll.insertAtEnd(value);
                break;
        case 4:
                cout<<"Enter position"<<endl;
                cin>>position;
                ll.deleteAtMiddle(position);
                break;
        case 5:
                cout<<"Enter value to be search"<<endl;
                cin>>value;
                ll.search(value);
                break;
        case 6:
                ll.printLL();
                break;
        case 7: exit(0);
    }

 }

    return 0;

}
