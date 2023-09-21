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
    pair<int, int> solve(TreeNode* root) {
        if(root == NULL) {
            return make_pair(0,0);
        }
        
        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);
        
        int lh = left.first;
        int rh = right.first;
        int ld = left.second;
        int rd = right.second;
        
        int height = 1 + max(lh, rh);
        int diameter = max(lh + rh, max(ld, rd));
        
        return make_pair(height, diameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second;
    }
};