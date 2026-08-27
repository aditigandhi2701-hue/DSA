class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int count = 0;

        // Check if there are k nodes
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        // Less than k nodes → don't reverse
        if (count < k)
            return head;

        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // head is now the last node of reversed group
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};