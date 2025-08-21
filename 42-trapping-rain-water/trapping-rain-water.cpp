class Solution {
public:
    int trap(vector<int>& h) {
       int ans=0;
       int l=0;
       int r=h.size()-1;
       int lmax=0,rmax=0;
       while(l<r){
        lmax=max(lmax,h[l]);
        rmax=max(rmax,h[r]);
        if(lmax<rmax){
            ans+=lmax-h[l];
            l++;
        }else{
            ans+=rmax-h[r];
            r--;
        }
       } 
       return ans;
    }
};