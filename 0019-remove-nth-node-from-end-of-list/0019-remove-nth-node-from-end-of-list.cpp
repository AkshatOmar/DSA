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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL) {
            temp = temp->next;
            len++;
        }
        
        if(n == len) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        int target = len - n;
        temp = head;
        for(int i = 1;i<target;i++) {
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
    }
};