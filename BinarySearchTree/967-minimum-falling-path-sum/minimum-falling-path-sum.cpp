class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n=matrix.size();

      for(int row=n-2;row>=0;row--){
        for(int col=0;col<=n-1;col++){
            if(col==0){
             matrix[row][col]=matrix[row][col]+min(matrix[row+1][col],matrix[row+1][col+1]);
            }else if(col==n-1){
                matrix[row][col]=matrix[row][col]+min(matrix[row+1][col],matrix[row+1][col-1]);
            }else{
                matrix[row][col]=matrix[row][col]+min(matrix[row+1][col-1],min(
                    matrix[row+1][col],matrix[row+1][col+1]
                ));
            }
        }
      } 

      int minsum=INT_MAX;
      for(int i=0;i<n;i++){
       minsum=min(minsum,matrix[0][i]);
      } 
      return minsum;
    }
};