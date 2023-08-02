class Solution {
public:
    void helper(vector<int> nums, int index, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            helper(nums, index+1, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};