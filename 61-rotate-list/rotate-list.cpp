class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and last node
        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: Make circular
        temp->next = head;

        // Step 3: Reduce k
        k = k % n;
        int stepsToNewTail = n - k;

        // Step 4: Find new tail
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};