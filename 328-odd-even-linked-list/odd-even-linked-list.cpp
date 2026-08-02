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
    ListNode* oddEvenList(ListNode* head) {

        //empty list or only one node
        if(head==nullptr || head->next==nullptr)
        return head;

        //first odd node
        ListNode* odd = head;

        //first even node
        ListNode* even = head->next;

        //save start of even list
        ListNode* evenHead = even;

        while(even != nullptr && even->next != nullptr){
            //link current odd node to next odd
            odd->next = even->next;
            //move odd pointer
            odd = odd->next;
            //link current even to next even 
            even->next = odd->next;
            //move even pointer 
            even = even->next;

        }//attach even list after odd list
        odd->next = evenHead;
        return head;


    }
};