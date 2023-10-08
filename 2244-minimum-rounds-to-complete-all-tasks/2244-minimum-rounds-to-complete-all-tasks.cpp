class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        int n = tasks.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            mp[tasks[i]]++;
        }
        
        for(auto i : mp) {
            if(i.second < 2) {
                return -1;
            }
            
            if(i.second == 2) {
                ans++;
            } else {
                ans += ceil((double)(i.second / 3.0));
            }
        }
        
        return ans;
    }
};