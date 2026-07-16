class Solution {
public:
    double power(double x,long long n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2!=0){
            return x*power(x,n-1);
        }
        double half=power(x,n/2);
        return half*half;
    }
    double myPow(double x, int n) {
        double ans = 0;
        long long N=n;
        if (n < 0) {
            N=-N;
            ans = 1/power(x, N);
        } else {
            ans = power(x, n);
        }
        return ans;
    }
};