//concept of dummy node....

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode*Dummy_node=new ListNode(-1);
//         ListNode*curr=Dummy_node;
//         int carry=0;
//         int sum=0;
//         ListNode *temp1=l1;
//         ListNode *temp2=l2;

//         while(temp1!=nullptr || temp2!=nullptr){
//             int val1=(temp1!=nullptr)?temp1->val:0;
//             int val2=(temp2!=nullptr)?temp2->val:0;
//             sum=val1+val2+carry;
//             ListNode *nw=new ListNode(sum%10);
//             curr->next=nw;
//             curr=curr->next;
//             carry=sum/10;
//             if(temp1!=nullptr)temp1=temp1->next;
//             if(temp2!=nullptr)temp2=temp2->next;
            
//         }
//         if (carry > 0) {
//             curr->next = new ListNode(carry);
//             curr=curr->next;
//         }
//         return Dummy_node->next;
//     }
// };