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
    int helper(TreeNode* root, int &maxi) {
        if(!root) return 0;
        // traverse till left and get its vaule
        // if it is negative then take it 0;
        int left = max(helper(root->left, maxi),0);
        //same for right
        int right = max(helper(root->right,maxi),0);
        // add root's val with left and right's value and update if maximum
        maxi = max(maxi,root->val+left+right);
        //return the maximum of left and right and add root's val with it
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        //declare maxi to return maximum path su
        if(root == NULL) return 0;
        int maxi = -1e9;
        //pass root and maxi by reference
        helper(root,maxi);
        return maxi;
    }
};