class Solution {
public:

void makerow(vector<vector<int>>&matrix,int m,int i){
    for(int j=0;j<m;j++){
        if(matrix[i][j]!=0){
       matrix[i][j]=-151;
    }
    }
}
void makecol(vector<vector<int>>&matrix,int n,int j){
for(int i=0;i<n;i++){
    if(matrix[i][j]!=0){
       matrix[i][j]=-151;
    }
}
}

    void setZeroes(vector<vector<int>>& matrix) {

        int r=matrix.size();
        int c=matrix[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(matrix[i][j]==0){
                  makerow(matrix,c,i);
                  makecol(matrix,r,j);
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==-151){
                    matrix[i][j]=0;
                }
            }
        }


    }
};