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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()) {
            int size = q.size();
            int maxCol = INT_MIN;
            int minCol = INT_MAX;
            int base = q.front().second;
            for(int i = 0;i<size;i++) {
                TreeNode* node = q.front().first;
                int col  = q.front().second;
                col-=base;
                q.pop();
                maxCol = max(maxCol,col);
                minCol = min(minCol,col);
                if(node->left)q.push({node->left,2LL*col});
                if(node->right)q.push({node->right,2LL*col+1});
            }
            ans = max(maxCol-minCol+1,ans);
        }
        return ans;

    }
};