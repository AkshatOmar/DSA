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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>>qp;
        qp.push({p,q});
        while(!qp.empty()) {
            auto it = qp.front();
            qp.pop();
            TreeNode* node1 = it.first;
            TreeNode* node2 = it.second;
            if(node1 == NULL && node2 == NULL) continue;
            if(node1 == NULL || node2 == NULL) return false;
            if(node1->val != node2->val) return false;
            qp.push({node1->left,node2->left});
            qp.push({node1->right,node2->right});
        }
        return true;
    }
};