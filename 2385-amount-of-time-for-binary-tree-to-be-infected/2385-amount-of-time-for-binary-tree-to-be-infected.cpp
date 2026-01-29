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
    TreeNode* treeToGraph(TreeNode* root, int start, unordered_map<TreeNode*,TreeNode*>&mp) {
        queue<TreeNode*>q;
        TreeNode* target = NULL;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0;i<n;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->val == start){
                    target = node;
                } 
                if(node->left) {
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right) {
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        //As we dont have connectiviy to upper node 
        //so we will make a parent map that will connect every node with its paernt like in graphs 
        // and at the same time we will find the target Node.
        //We will create a map having key->childNode, value->parent Node;
        unordered_map<TreeNode*, TreeNode*>mp;
        TreeNode* targetNode = treeToGraph(root,start,mp);
        queue<TreeNode*>q;

        q.push(targetNode);
        unordered_map<TreeNode*, bool>visited;
        visited[targetNode] = true;
        int time = 0;
        while(!q.empty()) {
            int n = q.size();
            bool burnt = false;
            for(int i = 0;i<n;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                    burnt = true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                    burnt = true;
                }
                if(mp[node] && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                    burnt = true;
                }
                if(burnt)time++;
            }
        }
        return time;
    }
};