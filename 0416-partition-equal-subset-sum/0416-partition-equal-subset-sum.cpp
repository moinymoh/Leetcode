class Solution {
public:
    bool solve(int index, vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
        if(target == 0) {
            return true;
        }
        
        if(index == n && target != 0) {
            return false;
        }
        
        if(dp[index][target] != -1) {
            return dp[index][target] ;
        }
        if(target < nums[index]) {
            return dp[index][target] = solve(index + 1, nums, n, target, dp);
        }
        
        bool include = solve(index + 1, nums, n, target - nums[index], dp);
        bool exclude = solve(index + 1, nums, n, target, dp);
        
        return dp[index][target] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }
        if(sum % 2 != 0) {
            return false;
        }
        int n = nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
        return solve(0, nums, n, sum / 2, dp);
    }
};