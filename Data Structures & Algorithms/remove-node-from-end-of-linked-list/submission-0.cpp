
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        // Return updated head
        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};
