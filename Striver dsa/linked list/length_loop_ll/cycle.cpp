// class Solution
// {
// public:
//     // Function to find the length of a loop in the linked list.
//     int countNodesinLoop(Node *head)
//     {
//         Node *slow = head;
//         Node *fast = head;
//         while (fast != nullptr && slow != nullptr)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast)
//             {
//                 int count = 0;
//                 Node *temp = slow;
//                 while (temp != slow)
//                 {
//                     count++;
//                     temp = temp->next;
//                 }
//                 return count;
//             }
//         }
//         return 0;
//     }
// };