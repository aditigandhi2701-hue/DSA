class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If there is only one node
        if (head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is the middle node
        // prev is the node before middle
        prev->next = slow->next;

        return head;
    }
};