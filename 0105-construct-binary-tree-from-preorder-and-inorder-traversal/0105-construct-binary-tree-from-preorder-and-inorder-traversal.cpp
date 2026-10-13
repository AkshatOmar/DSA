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
    TreeNode* treeBuilder(vector<int>&preorder,vector<int>&inorder, int inStart,int inEnd,int &preidx,unordered_map<int,int>&inMap) {
        if(inStart>inEnd) return NULL;
        int rootval = preorder[preidx++];
        TreeNode* root = new TreeNode(rootval);
        int inidx = inMap[rootval];
        root ->left = treeBuilder(preorder,inorder,inStart,inidx-1,preidx,inMap);
        root->right = treeBuilder(preorder,inorder,inidx+1,inEnd,preidx,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int>inMap;
        for(int i = 0;i<inorder.size();i++) {
            inMap[inorder[i]] = i;
        }
        int preidx = 0;
        TreeNode* root = treeBuilder(preorder,inorder,0,inorder.size()-1,preidx,inMap);
        return root;
    }
};