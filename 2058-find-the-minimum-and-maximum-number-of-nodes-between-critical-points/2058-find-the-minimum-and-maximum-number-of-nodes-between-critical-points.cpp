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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1,-1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;
        
        int minCritical = INT_MAX;
        int maxCritical = INT_MIN;
        int minDist = INT_MAX;
        int idx = 2;
        while(nxt != NULL) {
            if((curr->val < prev->val && curr->val < nxt->val) || (curr->val > prev->val && curr->val > nxt->val)){
                minCritical = min(idx,minCritical);
                if(maxCritical != INT_MIN)
                    minDist = min(minDist,idx-maxCritical);
                maxCritical=idx;
                
            }
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
            idx++;
        }
        if(minDist ==INT_MAX) return {-1,-1};
        int maxDist = maxCritical - minCritical;
        return {minDist,maxDist};
    }
};