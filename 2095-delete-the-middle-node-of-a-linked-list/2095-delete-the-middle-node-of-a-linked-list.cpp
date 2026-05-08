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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head ->next == NULL) return NULL;
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL) {
            temp = temp->next;
            n++;
        }
        int mid = n/2;
        int ptr = 0;
        temp = head;
        while(ptr != mid-1) {
            temp = temp->next;
            ptr++;
        }
        temp->next = temp->next->next;
        return head;
    }
};