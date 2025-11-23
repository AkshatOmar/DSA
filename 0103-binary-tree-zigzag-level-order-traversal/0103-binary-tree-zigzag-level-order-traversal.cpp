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
    void helper(TreeNode* root, vector<vector<int>>&res) {
        if(root == NULL) return;
        deque<TreeNode*>dq;
        dq.push_back(root);
        bool reverse = false;
        while(!dq.empty()) {
            vector<int>lvl;
            int size = dq.size();
           
            for(int i = 0;i<size;i++) {
                if(reverse == false) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    lvl.push_back(node->val);
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                }
                else{
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    lvl.push_back(node->val);
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                }
            }
            res.push_back(lvl);
            reverse = !reverse;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL) return res;
        helper(root, res);
        return res;
    }
};