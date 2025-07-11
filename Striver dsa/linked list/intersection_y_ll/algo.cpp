
// class Solution
// {

// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         int lenA = 0, lenB = 0;
//         ListNode *tempA = headA, *tempB = headB;

//         while (tempA != nullptr)
//         {
//             lenA++;
//             tempA = tempA->next;
//         }

//         while (tempB != nullptr)
//         {
//             lenB++;
//             tempB = tempB->next;
//         }
//         tempA = headA;
//         tempB = headB;

//         if (lenA > lenB)
//         {
//             int len = lenA - lenB;
//             while (len)
//             {
//                 len--;
//                 tempA = tempA->next;
//             }
//         }
//         else
//         {
//             int len = lenB - lenA;
//             while (len)
//             {
//                 len--;
//                 tempB = tempB->next;
//             }
//         }

//         while (tempA != nullptr || tempB != nullptr)
//         {
//             if (tempA == tempB)
//             {
//                 return tempA;
//             }
//             else
//             {
//                 tempA = tempA->next;
//                 tempB = tempB->next;
//             }
//         }
//         return nullptr;
//     }
// };