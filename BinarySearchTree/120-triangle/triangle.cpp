class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int m=triangle.size();
      
      for(int i=m-2;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            int down=triangle[i+1][j];
            int diagonal=triangle[i+1][j+1];
           triangle[i][j]=triangle[i][j]+min(down,diagonal);
        }
      }
 return triangle[0][0];
    }
};