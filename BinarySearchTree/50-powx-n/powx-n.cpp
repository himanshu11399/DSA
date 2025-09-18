class Solution {
public:
   double solve(double x,long n){
    if(n==0) return 1;   //When the n is null 
    if(n<0) return solve(1/x,-n);  //when the pow is neagtive use binary Exponential  Method
    if(n%2==0) return solve(x*x,n/2);  //when the pow is even
    return x*solve(x*x,(n-1)/2);  //when the pow is odd
   }
    double myPow(double x, int n) {
       return solve(x,(long)n); //call the function
    }
};