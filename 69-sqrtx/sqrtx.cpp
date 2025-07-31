class Solution {
public:
    int mySqrt(int x) {
        long low=0;
        long high=x;
        while(low<=high){
            long mid=(low+high)/2;
            long long sqr=mid*mid;
            if(sqr==x){
                return mid;
            }else if(sqr>x){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return high;
    }
};