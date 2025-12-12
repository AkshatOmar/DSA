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
    int maxDistance = 0;
public:
    int helper(TreeNode* root,int start) {
        int depth = 0;
        if(root == NULL) return depth;
        int left = helper(root->left, start);
        int right = helper(root->right, start);
        if(root->val == start) {
            maxDistance = max(left,right);
            depth = -1;
        }else if(left >=0 && right >= 0){
            depth = max(left,right)+1;
        }else {
            int distance = abs(left) + abs(right);
            maxDistance = max(maxDistance, distance);
            depth = min(left,right)-1;
        }
        return depth;
    }
    int amountOfTime(TreeNode* root, int start) {
        helper(root, start);
        return maxDistance;
    }
};