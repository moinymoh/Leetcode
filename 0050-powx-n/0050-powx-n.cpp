class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
        if(n == INT_MIN){
            x = x * x;
            n = n/2;
        }
        if(n<0){
            n = -n;
            x = 1/x;
        }
        double xnb2 = myPow(x, n / 2);
        double ans = xnb2 * xnb2;
        
        if(n % 2 == 1){
            ans *= x;
        }
        return ans;
    }
};