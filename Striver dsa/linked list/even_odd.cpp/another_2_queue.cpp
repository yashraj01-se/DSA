// #include<queue>
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         ListNode* temp_odd=head;
//         ListNode* temp_even=head->next;
//         queue<int>q_odd;
//         queue<int>q_even;
//         while(temp_odd!=nullptr){
//             q_odd.push(temp_odd->val);
//             if(temp_odd->next!=nullptr && temp_odd->next->next!=nullptr)temp_odd=temp_odd->next->next;
//             else{
//                 temp_odd=nullptr;
//             }
//         }
//          while(temp_even!=nullptr){
//             q_even.push(temp_even->val);
//             if(temp_even->next!=nullptr && temp_even->next->next!=nullptr)temp_even=temp_even->next->next;
//             else{
//                 temp_even=nullptr;
//             }
//         }
//         ListNode*temp=head;
//         while(!q_odd.empty()){
//             temp->val=q_odd.front();
//             q_odd.pop();
//             temp=temp->next;
//         }
//         while(!q_even.empty()){
//             temp->val=q_even.front();
//             q_even.pop();
//             temp=temp->next;
//         }
//         return head;
//     }
// };