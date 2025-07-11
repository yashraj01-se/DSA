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

    cout << "linked list before deletion of kth element:";
    Node *temp1 = y;
    while (temp1 != nullptr)
    {
        cout << temp1->data << "->";
        temp1 = temp1->next;
    }
    cout << "null" << endl;

    Node *temp2 = y;
    cout << "enter your position to delete"<<endl;
    int k;
    cin >> k;
    if (k <= 0) {
        cout << "Invalid position." << endl;
        return 0;
    }
    if(k==1){
        Node *todel=y;
        y=y->next;
        delete todel;
    }
    else{
    int count = 1;
    temp1=y;   // reinitailized;
    while (count < k && temp1!=nullptr)
    {
        temp1 = temp1->next;
        count++;
    }
    if(temp1 == nullptr) {
        cout << "Position out of range." << endl;
        return 0;
    }
    while (temp2->next != temp1)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1->next;
    delete temp1;

}

    cout << "linked list after deletion of kth element:";
    temp2=y;
    while (temp2 != nullptr)
    {
        cout << temp2->data << "->";
        temp2= temp2->next;
    }
    cout << "null";
    return 0;
}