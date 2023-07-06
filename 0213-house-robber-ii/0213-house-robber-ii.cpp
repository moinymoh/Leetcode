class Solution {
public:
    int solve(vector<int> nums, int currIndex, vector<int>& dp, int n){
        if(currIndex >= n){
            return 0;
        }
        
        int currKey = currIndex;
        if(dp[currKey] != -1){
            return dp[currKey];
        }
        int include = nums[currIndex] + solve(nums, currIndex + 2, dp, n);
        int exclude = solve(nums, currIndex + 1, dp, n);
        
        dp[currKey] = max(include, exclude);
        return max(include, exclude);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        
        return max(solve(nums, 0, dp1, n - 1), solve(nums, 1, dp2, n));
    }
};