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
   void mapParent(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& mp){
        if(root == NULL){
            return;
        }
        
        mp[root] = parent;
        mapParent(root -> left, root, mp);
        mapParent(root -> right, root, mp);
    }
    void solve(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& mp, vector<int>& ans, set<int>& visited, TreeNode* target){
        if(root == NULL){
            return;
        }
        if(visited.find(root -> val) != visited.end()){
            return;
        }
        
        visited.insert(root -> val);
        if(k == 0){
            ans.push_back(root -> val);
            return;
        }
        
        solve(root -> left, k - 1, mp, ans, visited, target);
        solve(root -> right, k - 1, mp, ans, visited, target);
        solve(mp[root], k - 1, mp, ans, visited, target);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mapParent(root, NULL, mp);
        
        vector<int> ans;
        set<int> visited;
        solve(target, k, mp, ans, visited, target);
        return ans;
    }
};