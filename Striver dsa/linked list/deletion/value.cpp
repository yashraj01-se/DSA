#include <iostream>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

int main()
{
    Node *y = new Node(2);
    y->next = new Node(3);
    y->next->next = new Node(4);

    cout << "linked list before deletion of element:";
    Node *temp1 = y;
    while (temp1 != nullptr)
    {
        cout << temp1->data << "->";
        temp1 = temp1->next;
    }
    cout << "null" << endl;

    cout << "enter the element you want to delete" << endl;
    int ele;
    cin >> ele;
    int k = 1;
    Node *temp2 = y;
    temp1=y;
    if (k == 1 && temp1->data == ele)
    {
        Node *tem = y;
        y = y->next;
        delete tem;
    }
    else
    {
        
        while (temp1->data!= ele && temp1 != nullptr)
        {
            temp1 = temp1->next;
        }

        while (temp2->next != temp1)
        {
            temp2 = temp2->next;
        }
        if(temp1==nullptr){
           cout<<"No such element exist."<<endl;
        }else{
            temp2->next=temp1->next;
        delete temp1;
        }
       
        
    }

    cout << "linked list after deletion of element:";
    temp2=y;
    while (temp2 != nullptr)
    {
        cout << temp2->data << "->";
        temp2= temp2->next;
    }
    cout << "null";
    return 0;

}