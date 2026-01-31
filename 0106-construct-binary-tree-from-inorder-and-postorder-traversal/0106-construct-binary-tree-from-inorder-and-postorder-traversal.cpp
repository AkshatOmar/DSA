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
    TreeNode* TreeBuilder(vector<int>&inorder,vector<int>&postorder,int inStart,int inEnd,int &postidx, unordered_map<int,int>&mp) {
        if(inStart>inEnd)return NULL;
        int rootval = postorder[postidx--];
        TreeNode* root = new TreeNode(rootval);
        int inidx = mp[rootval];
        root->right = TreeBuilder(inorder,postorder,inidx+1,inEnd,postidx,mp);
        root->left = TreeBuilder(inorder,postorder,inStart,inidx-1,postidx,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n = inorder.size();
        for(int i = 0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        int postidx = n-1;
        return TreeBuilder(inorder,postorder,0,n-1,postidx,mp);
    }
};