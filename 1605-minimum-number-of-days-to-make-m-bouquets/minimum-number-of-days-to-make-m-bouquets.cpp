class Solution {
public:
    int maxday(vector<int>&bloomDay){
        int ans=bloomDay[0];
        for(int i=1;i<bloomDay.size();i++){
          if(bloomDay[i]>ans){
            ans=bloomDay[i];
          }
        }
        return ans;
    }

    int canwemake(vector<int>&bloomDay,int mid,int k){
        int boqcount=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                count=0;
            }
            if(count==k){
                boqcount++;
                count=0;
            }
        }
        return boqcount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int low=0;
       int high=maxday(bloomDay);
       int ans=-1;

       while(low<=high){

        int mid=(low+(high-low)/2);

        if(canwemake(bloomDay,mid,k)>=m){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
       } 
       return ans;
    }
};