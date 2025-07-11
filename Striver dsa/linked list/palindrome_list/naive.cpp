// /****************************************************************

//     Following is the class structure of the Node class:

//     class Node
//     {
//     public:
//         int data;
//         Node *next;
//         Node()
//         {
//             this->data = 0;
//             next = NULL;
//         }
//         Node(int data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//         Node(int data, Node* next)
//         {
//             this->data = data;
//             this->next = next;
//         }
//     };

// *****************************************************************/
// #include<stack>
// bool isPalindrome(Node *head)
// {
//     Node* temp=head;
//     stack<int>st;
//    while(temp!=nullptr){
//       st.push(temp->data);
//       temp=temp->next;
//    }
//    temp=head;
//    while(temp!=nullptr){
//        if(temp->data!=st.top()){
//            return false;
//        }
//        temp=temp->next;
//        st.pop();
//     }
//     return true;
// }