class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int piv=-1;
      int n=nums.size();

      //Step-1 To find the pivot element
      for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            piv=i;
            break;
        }
      }
      //Check if the arr is in decreasing order means no next permutation  is possible
      if(piv==-1){
        reverse(nums.begin(),nums.end());
        return;
      }

      //Step-2 Find the next most of the pivot element
      for(int i=n-1;i>piv;i--){
         if(nums[piv]<nums[i]){
            swap(nums[piv],nums[i]);
            break;
         }
      }

      //Step-3 rev all the remaining element
      int i=piv+1;
      int j=n-1;
      while(i<=j){
        swap(nums[i],nums[j]);
        i++;
        j--;
      }


    }
};