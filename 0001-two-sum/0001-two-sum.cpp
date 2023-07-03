class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int size = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < size; i++){
            int x = target - nums[i];
            if(mp.find(x) != mp.end()) {
                ans.push_back(mp[x]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        
        return ans;
    }
};