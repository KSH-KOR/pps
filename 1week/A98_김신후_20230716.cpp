/*

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            // Move the pointers to the next nodes
            pA = (pA != nullptr) ? pA->next : headB;
            pB = (pB != nullptr) ? pB->next : headA;
        }

        // Return the intersection node or nullptr if no intersection exists
        return pA;
    }
};
