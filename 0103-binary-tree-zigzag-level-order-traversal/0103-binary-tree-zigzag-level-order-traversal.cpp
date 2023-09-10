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
    void solve(TreeNode* root, vector<vector<int>>& output) {
        if(root == NULL) {
            return;
        }
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> ans;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();
                ans.push_back(front -> val);

                if(front -> left != NULL) {
                    q.push(front -> left);
                }

                if(front -> right != NULL) {
                    q.push(front -> right);
                }
            }
            if ( !leftToRight ) {
                reverse(ans.begin(), ans.end());
                
            }
            leftToRight = !leftToRight;
            output.push_back(ans);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> output;
        solve(root, output);
        return output;
    }
};