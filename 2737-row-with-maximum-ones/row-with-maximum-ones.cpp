class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int row=mat.size();
        int col=mat[0].size();
        int maxrow=0;
        int maxcount=0;
        
        for(int i=0;i<row;i++){
            int count=0;
            for(int j=0;j<col;j++){
               if(mat[i][j]==1){
                count++;
               }
            }
            if(maxcount<count){
                maxcount=count;
                maxrow=i;
            }
        }

        ans.push_back(maxrow);
        ans.push_back(maxcount);
        return ans;

    }
};