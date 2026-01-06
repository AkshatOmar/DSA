/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int maxSum = INT_MIN;
        int maxlvl = 1;
        int currlvl = 1;
        while(!q.empty()) {
            int sum = 0;
            int size = q.size();
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(maxSum<sum) {
                maxSum = sum;
                maxlvl = currlvl;
            }
            currlvl++;
        }
        return maxlvl;
    }
};