class Solution {
private:
//     void helper(string digits, int index, string arr[], string output, vector<string>& ans){
//         if(index >= digits.size()){
//             ans.push_back(output);
//             return;
//         }
        
//         int element = digits[index] - '0';
//         string value = arr[element];
        
//         for(int i = 0; i < value.size(); i++){
//             output.push_back(value[i]);
//             helper(digits, index + 1, arr, output, ans);
//             output.pop_back();
//         }
//     }
public:
    void helper(string digits, int index, string arr[], string output, vector<string>& ans){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        
        int element = digits[index] - '0';
        string value = arr[element];
        
        for(int i = 0; i < value.size(); i++){
            helper(digits, index + 1, arr, output + value[i], ans);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        if(digits.size() == 0){
            return ans;
        }
        string arr[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(digits, 0, arr, output, ans);
        return ans;
    }
};