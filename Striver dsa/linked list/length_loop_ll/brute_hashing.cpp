// class Solution {
//   public:
//     // Function to find the length of a loop in the linked list.
//     int countNodesinLoop(Node *head) {
//         Node*temp=head;
//         int timer=1;
//         unordered_map<Node*,int>mpp;
//         while(temp!=nullptr){
//            if(mpp.find(temp)!=mpp.end()){
//                int val=mpp[temp];
//                return timer-val;
//            }
//            mpp[temp]=timer;
//            timer++;
//            temp=temp->next;
//         }
//         return 0;
//     }
// };