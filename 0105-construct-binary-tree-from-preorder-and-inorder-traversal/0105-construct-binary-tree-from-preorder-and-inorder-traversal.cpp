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

    int idx = 0;
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&inMap) {
        if(inStart>inEnd)return NULL;
        int rootval = preorder[idx++];
        TreeNode* root = new TreeNode(rootval);
        int inidx = inMap[rootval];
        root->left = treeBuilder(preorder,inorder,inStart,inidx-1,inMap);
        root->right = treeBuilder(preorder,inorder,inidx+1,inEnd,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inMap;
        for(int i = 0;i<inorder.size();i++) {
            inMap[inorder[i]] = i;
        }
        return treeBuilder(preorder,inorder,0,inorder.size()-1,inMap);
    }
};