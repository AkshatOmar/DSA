/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentAccess(TreeNode* root, map<TreeNode*,TreeNode*>&mp) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0;i<n;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) {
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    vector<int>DisFromTarget(TreeNode* root, TreeNode* target, int k, map<TreeNode*,TreeNode*>& mp) {
        queue<TreeNode*>q;
        vector<int>res;
        q.push(target);
        unordered_set<TreeNode*>visited;
        int currlvl = 0;
        visited.insert(target);
        while(!q.empty()) {
            int n = q.size();
            if(currlvl++ == k) break;
            for(int i = 0;i<n;i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(mp.count(node) && visited.find(mp[node]) == visited.end()){
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
        }
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        parentAccess(root,mp);
        return DisFromTarget(root,target,k,mp);
    }
};