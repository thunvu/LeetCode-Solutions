/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Base case: Both nodes are null
        if (l1 == nullptr && l2 == nullptr) return nullptr;

        // Add dummy node if l1 or l2 end first
        if (l1 == nullptr) l1 = new ListNode(0);
        if (l2 == nullptr) l2 = new ListNode(0);

        int sum = l1->val + l2->val;

        // Add 1 to l1's next node if sum has carry
        if (sum >= 10) {
            sum -= 10;
            if (l1->next == nullptr) {
                l1->next = new ListNode(1);
            } else {
                l1->next->val += 1;
            }
        }

        ListNode* result = new ListNode(sum);

        // recursion
        result->next = addTwoNumbers(l1->next, l2->next);
        
        return result;
    }
};