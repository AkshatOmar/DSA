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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root == NULL) return res;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* leftNode= curr->left;
                while(leftNode->right != NULL) {
                    leftNode = leftNode->right;
                }
                leftNode->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};