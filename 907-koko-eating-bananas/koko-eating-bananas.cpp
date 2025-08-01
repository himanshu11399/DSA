class Solution {
public:
int maxnum(vector<int>&piles){
    int ans=piles[0];
    for(int i=1;i<piles.size();i++){
        if(piles[i]>ans){
            ans=piles[i];
        }
    }
    return ans;
}
    int minEatingSpeed(vector<int>& piles, int h) {
      int low=1;
      int high=maxnum(piles); 
      int ans=high; 
      while(low<=high){
        long  mid=(low+(high-low)/2);
        long speed=0;

        for(int i=0;i<piles.size();i++){
            speed+=(piles[i]+mid-1)/mid;
        }

        if(speed<=h){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }

      }
      return ans;
    }
};