class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        // for(auto &i: v){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        int ans = 0,e = v[0][1];
        for(int i = 1; i < v.size(); i++){
            // cout<<v[i][0]<<" "<<e<<endl;
            if(v[i][0]<e){
                ans++;
            }else
            e = v[i][1];
        }
        return ans;
    }
};