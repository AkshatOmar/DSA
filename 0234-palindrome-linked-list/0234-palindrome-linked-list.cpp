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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL) {
            slow = slow ->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* nxt = NULL;
        while(curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode* start = head;
        ListNode* end = prev;
        while(end) {
            if(start->val != end->val) return false;
            start = start->next;
            end = end->next;
        }
        return true;
    }
};