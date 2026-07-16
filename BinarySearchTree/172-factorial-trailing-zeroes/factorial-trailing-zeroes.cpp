class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        int mul=5;
        while(n/mul!=0){
            count+=n/mul;
            mul*=5;
        }
        return count;
    }
};