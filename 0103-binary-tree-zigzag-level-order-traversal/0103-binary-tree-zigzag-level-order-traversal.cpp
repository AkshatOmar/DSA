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
        queue<TreeNode*>q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()) {
            vector<int>lvl;
            int size = q.size();
            if(cnt%2 == 0) {
                for(int i = 0;i<size;i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    lvl.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            else{
                for(int i = 0;i<size;i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    lvl.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                reverse(lvl.begin(),lvl.end());
            }
            cnt++;
            res.push_back(lvl);
            
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL) return res;
        helper(root, res);
        return res;
    }
};