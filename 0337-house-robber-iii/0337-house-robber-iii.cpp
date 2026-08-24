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
    pair<int,int> helper(TreeNode* root) {
        if(root == NULL) return {0,0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first,left.second) + max(right.first,right.second);
        return {withRoot,withoutRoot}; 
    }
    int rob(TreeNode* root) {
        auto ans = helper(root);
        return max(ans.first,ans.second);
    }
};