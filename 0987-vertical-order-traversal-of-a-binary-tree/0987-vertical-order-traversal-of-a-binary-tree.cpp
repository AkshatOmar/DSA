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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //declare map -> level,vertical,multiset to store node at each level
        map<int, map<int,multiset<int>>>nodes;
        //declare queue to store node, level, vrtical
        queue<pair<TreeNode*,pair<int, int>>>todo;
        //push root with its x,y coordinates;
        todo.push({root,{0,0}});
        while(!todo.empty()) {
            auto p = todo.front();
            //pop front
            todo.pop();
            //extract node
            TreeNode* temp = p.first;
            //Extract x and y axis;
            int x = p.second.first;
            int y = p.second.second;
            //insert node into map by vertical and level
            nodes[x][y].insert(temp->val);
            //if left exists, push with coordinates
            if(temp->left) {
                todo.push({temp->left,{x-1,y+1}});
            }
            //if right exists, push with coordinates

            if(temp->right) {
                todo.push({temp->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        //iterate through vertical in map
        for(auto p : nodes) {
            vector<int>col;
            //collect all nodes in order of levels.
            for(auto q : p.second) {
                col.insert(col.end(),q.second.begin(),q.second.end());

            }
            //push column in result;
            ans.push_back(col);
        }
        return ans;
    }
};