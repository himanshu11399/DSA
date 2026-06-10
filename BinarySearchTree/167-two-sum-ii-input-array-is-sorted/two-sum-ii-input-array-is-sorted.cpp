class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n=num.size();
        unordered_map<int, int> mpp;
        int i=0;
        int j=n-1;
        while(i<j){
            int total=num[i]+num[j];
          if(total==target){
            return {i+1,j+1};
          }else if(total<target){
            i++;
          }else{
            j--;
          }
        }
        return {-1, -1};
    }
};