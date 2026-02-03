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
    TreeNode* helper(vector<int>&inorder,vector<int>&postorder,int inStart,int inEnd,int &preidx,unordered_map<int,int>&inMap) {
        if(inStart>inEnd) return NULL;
        int rootval = postorder[preidx--];
        TreeNode* root = new TreeNode(rootval);
        int inidx = inMap[rootval];
        root->right = helper(inorder,postorder,inidx+1,inEnd,preidx,inMap);
        root->left = helper(inorder,postorder,inStart,inidx-1,preidx,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inMap;
        for(int i = 0;i<inorder.size();i++) {
            inMap[inorder[i]] = i;
        }
        int preidx = inorder.size()-1;
        return helper(inorder,postorder,0,inorder.size()-1,preidx,inMap);
    }
};