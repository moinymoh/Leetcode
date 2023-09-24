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
    void solve(TreeNode* root, int sum, int targetSum, vector<vector<int>>& ans, vector<int> output) {
        if(root == NULL) {
            return;
        }
        
        sum += root -> val;
        output.push_back(root -> val);
        
        if(sum == targetSum && root -> left == NULL && root -> right == NULL) {
            ans.push_back(output);
        }
        
        
        solve(root -> left, sum, targetSum, ans, output);
        solve(root -> right, sum, targetSum, ans, output);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> output;
        int sum = 0;
        solve(root, sum, targetSum, ans, output);
        return ans;
    }
};