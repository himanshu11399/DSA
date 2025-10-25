class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
       int i=0;
       while(i<interval.size()){
        if(interval[i][1]<newInterval[0]){
         i++;
        }else if(interval[i][0]>newInterval[1]){
            interval.insert(interval.begin()+i,newInterval);
            return interval;
        }else{
            newInterval[0]=min(newInterval[0],interval[i][0]);
            newInterval[1]=max(newInterval[1],interval[i][1]);
            interval.erase(interval.begin()+i);
        }
       }
       interval.push_back(newInterval);
       return interval; 
    }
};