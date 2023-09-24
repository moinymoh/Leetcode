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
    int count = 0;
    void solve(TreeNode* root, int target, vector<int>& output) {
        if(root == NULL) {
            return;
        }
        
        output.push_back(root -> val);
        solve(root -> left, target, output);
        solve(root -> right, target, output);
        
        int size = output.size();
        long long sum = 0;
        for(int i = size -1 ; i >= 0; i--){
            sum += output[i];
            if(sum == target){
                count++;
            }
        }
        output.pop_back();
        // int sum = 0;
        // for(int i = 0; i < output.size(); i++) {
        //     sum += output[i];
        //     if(sum == target) {
        //         count++;
        //     }
        // }
        // output.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> output;
        solve(root, targetSum, output);
        return count;
    }
};