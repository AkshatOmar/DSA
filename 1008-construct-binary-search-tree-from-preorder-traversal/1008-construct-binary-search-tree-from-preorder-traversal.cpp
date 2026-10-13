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
    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int stPre,int preEnd,int inSt,int inEnd,unordered_map<int,int>&mp) {
        if(stPre > preEnd || inSt>inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[stPre]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot-inSt;
        root->left = helper(preorder,inorder,stPre+1,stPre+numsLeft,inSt,inRoot-1,mp);
        root->right = helper(preorder,inorder,stPre+numsLeft+1,preEnd,inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();

        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = helper(preorder,inorder,0,n-1,0,n-1,mp);
        return root;
    }
};