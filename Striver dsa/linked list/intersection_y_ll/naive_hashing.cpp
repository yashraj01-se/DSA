
// #include<unordered_map>
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* temp1=headA;
//          unordered_map<ListNode*,bool>mpp;
//         while(temp1!=nullptr){
//             mpp[temp1]=true;
//             temp1=temp1->next;
//         }
//         temp1=headB;
//         while(temp1!=nullptr){
//             if(mpp.find(temp1)!=mpp.end()){
//                 return temp1;
//             }
//             else{
//                 temp1=temp1->next;
//             }
//         }
//         return nullptr;
//     }
   
// };