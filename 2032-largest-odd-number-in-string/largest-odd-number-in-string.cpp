class Solution {
public:
    string largestOddNumber(string nums) {
        for(int i=nums.size()-1;i>=0;i--){
            if((nums[i]-'0')%2!=0){
              return nums.substr(0,i+1);
            }
        }return "";
    }
};