class Solution {
public:
    int solve(vector<int>& nums, int index, int n, vector<int>& dp){
        if(index >= n - 1){
            return 0;
        }
       // if(nums[index] == 0){
       //      return 10001;
       //  } 
        if(dp[index] != -1){
            return dp[index];
        }
        
        int currentJumps = nums[index];
        int ans = 10001;
        for(int x = 1; x <= currentJumps; x++){
            int temp = 1 + solve(nums, index + x, n, dp);
            ans = min(ans, temp);
        }
        return dp[index] = ans;
        // return false;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, n, dp);
//         int n = nums.size();
//         // int *dp = new int[n+1];
//         vector<int> dp(n, 0);
        
//         dp[n-1] = 0;
        
//         for(int i = n-2; i >= 0; i--){
//             if(nums[i] == 0){
//                 dp[i] = 0;
//             }
//             int mn = INT_MAX;
//             for(int j = 1; j <= nums[i] && i + j < nums.size(); j++){
//                 mn = min(mn, dp[i+j]);
//             }
//             if(mn == INT_MAX){
//                 dp[i] = mn;
//             }else{
//                 dp[i] = 1 + mn;
//             }
//         }
//         return dp[0];
    }
};