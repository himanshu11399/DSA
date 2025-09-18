class Solution {
public:
    const long long MOD=1e9+7;
    long long pow(long long x,long long n){
        if(n==0) return 1;
        if(n==1) return x%MOD;
        if(n%2==0){
            long long half=pow((x*x)%MOD,n/2);
            return half%MOD;
        }else{
            long long half=pow((x*x)%MOD,(n-1)/2);
            return ((x%MOD)*(half%MOD))%MOD;
        }
        
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        return (pow(5,even)*pow(4,odd))%MOD;
    }
};