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
    int pairSum(ListNode* head) {
        //1.Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //2.Reverse second half
        ListNode* prev = nullptr;
        while(slow != nullptr){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;

        }
        //3. Compare pairs
        int ans = 0;
        ListNode* first = head;
        ListNode* second = prev;
         while (second != nullptr) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;

        
    }
};