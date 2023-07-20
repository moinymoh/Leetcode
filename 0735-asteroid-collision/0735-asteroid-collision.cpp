class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int size = asteroids.size();
        for(int i = 0; i < size; i++){
            int num = asteroids[i];
            
            if(num >= 0){
                st.push(num);
            }else{
                while(!st.empty() && abs(num) > st.top() && st.top() > 0){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(num)){
                    st.pop();
                }else if(!st.empty() && st.top() < 0){
                    st.push(num);
                }else if(st.empty()){
                    st.push(num);
                }   
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
            reverse(ans.begin(), ans.end());
        return ans;
    }
};