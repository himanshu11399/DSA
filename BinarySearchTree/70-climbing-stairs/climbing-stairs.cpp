class Solution {
public:
    // vector<int> dp;
    // int solve(int n) {
    //     if (n == 0 || n == 1)
    //         return 1;
    //     if (n < 0)
    //         return 0;
    //     if (dp[n] != 0)
    //         return dp[n];
    //     int one = climbStairs(n - 1);
    //     int two = climbStairs(n - 2);

    //     return dp[n]=one + two;
    // }

    int climbStairs(int n) {
        if (n <= 1)
            return 1;
        
        if(n<=1) return 1;
       int a=1,b=1;
       for(int i=2;i<=n;i++){
          int c=a+b;
          a=b;
          b=c;
       } 
       return b;
    }
};