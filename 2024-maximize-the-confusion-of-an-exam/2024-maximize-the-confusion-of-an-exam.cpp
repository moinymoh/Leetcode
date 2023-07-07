class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        
        int ansF = 0;
        int countF = 0;
        int n = answerKey.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(answerKey[i] == 'F'){
                countF++;
            }
            
            if(countF > k){
                if(answerKey[j] == 'F'){
                    countF--;
                }
                j++;
            }
            
            ansF = max(ansF, i - j + 1);
        }
        
        int ansT = 0;
        int countT = 0;
        n = answerKey.size();
        j = 0;
        for(int i = 0; i < n; i++){
            if(answerKey[i] == 'T'){
                countT++;
            }
            
            if(countT > k){
                if(answerKey[j] == 'T'){
                    countT--;
                }
                j++;
            }
            
            ansT = max(ansT, i - j + 1);
        }
        
        ans = max(ansT, ansF);
        return ans;
    }
};