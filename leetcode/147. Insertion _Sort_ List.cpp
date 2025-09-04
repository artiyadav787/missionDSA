class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode dummy(0); // dummy head of sorted list
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;  // store next node
            ListNode* prev = &dummy;

            // find position to insert
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy.next;
    }
};
