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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*>dq;
        vector<vector<int>>ans;
        if(root == nullptr) return ans;
        dq.push_back(root);
        int level = 0;
        while(!dq.empty()) {
            
            if(level%2 == 0) {
                int n = dq.size();
                vector<int>lvl;
                for(int i = 0;i<n;i++) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    lvl.push_back(node->val);
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                }
                ans.push_back(lvl);
            }
            else{
                int n = dq.size();
                vector<int>lvl;
                for(int i = 0;i<n;i++) {
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    lvl.push_back(node->val);
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                }
                ans.push_back(lvl);
            }
            level++;
        }
        return ans;
    }
};