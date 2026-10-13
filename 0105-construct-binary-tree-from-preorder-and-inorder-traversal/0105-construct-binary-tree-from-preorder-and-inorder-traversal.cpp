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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int inSt, int inEnd,int preSt, int preEnd, unordered_map<int,int>&mp) {
        if(preSt > preEnd || inSt > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preSt]);
        root->left = helper(preorder,inorder,inSt,mp[root->val]-1,preSt+1,preSt+mp[root->val]-inSt,mp);
        root->right = helper(preorder,inorder,mp[root->val]+1,inEnd,preSt+mp[root->val]-inSt+1,preEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root =  helper(preorder,inorder,0,n-1,0,n-1,mp);
        return root;
    }
};