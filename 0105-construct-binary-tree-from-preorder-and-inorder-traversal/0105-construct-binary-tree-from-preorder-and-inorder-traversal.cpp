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
    TreeNode* tree(vector<int>&preorder,vector<int>&inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>&inMap) {
        if(inStart>inEnd || preStart>preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot-inStart;
        root->left = tree(preorder,inorder,preStart+1,preStart+numsLeft,inStart,inRoot-1,inMap);
        root->right = tree(preorder,inorder,preStart+numsLeft+1,preEnd,inRoot+1,inEnd,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        for(int i = 0;i<inorder.size();i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode* root = tree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,inMap);
        return root;
    }

};