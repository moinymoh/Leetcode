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
    bool solve(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        } else if(p == NULL && q != NULL || q == NULL && p != NULL) {
            return false;
        }
        
        if(q -> val != p -> val) {
            return false;
        }
        
        return solve(p -> left, q -> right) && solve(p -> right, q -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if( root == NULL) {
            return true;
        }
        return solve(root -> left, root -> right);
    }
};