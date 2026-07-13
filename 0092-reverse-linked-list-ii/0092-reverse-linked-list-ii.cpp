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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        for(int i=1; i < left; i++) { // move prev ptr to just before left node
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* next = NULL;

        // save the connections
        ListNode* connect = prev;
        ListNode* tail = curr;

        // reverse the portion
        for(int i=0; i< right-left+1; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // reconnect the reversed portion
        connect->next = prev;
        tail->next = curr;

        return dummy->next;
    }
};