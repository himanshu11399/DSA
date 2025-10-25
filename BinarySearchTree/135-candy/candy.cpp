class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int>candy(n,1);

        //for left first;
        for(int i=1;i<n;i++){
         if(rating[i]>rating[i-1]){
            candy[i]=max(candy[i],candy[i-1]+1);
         }
        }

        //for right first
        for(int i=n-2;i>=0;i--){
            if(rating[i]>rating[i+1]){
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }
        
        int mincandy=0;
        for(int i=0;i<n;i++){
            mincandy+=candy[i];
        }

        return mincandy;
    }
};