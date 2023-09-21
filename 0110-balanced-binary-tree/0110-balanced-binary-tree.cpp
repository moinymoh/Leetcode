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
    pair<int, bool> solve(TreeNode* root) {
        if(root == NULL) {
            return make_pair(0, true);
        }
        
        pair<int, bool> left = solve(root -> left);
        pair<int, bool> right = solve(root -> right);
        
        int lh = left.first;
        int rh = right.first;
        int lb = left.second;
        int rb = right.second;
        
        int height = 1 + max(lh, rh);
        int diff = abs(lh - rh);
        bool isBal = diff <= 1;
        bool bal = lb && rb && isBal;
        
        return make_pair(height, bal);
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};