class Solution {
public:
    char repeatedCharacter(string s) {
        char ans;
        unordered_map<char, int> mp;
        int size = s.size();
        for(int i = 0; i < size; i++){
            mp[s[i]]++;
            if (mp[s[i]] >= 2) {
                ans = s[i];
                break;
            }
            cout << mp[s[i]];
            
        }
        return ans;
    }
};