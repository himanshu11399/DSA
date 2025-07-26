class Solution {
public:

void makerow(vector<vector<int>>&matrix,int m,int i){
    for(int j=0;j<m;j++){
        if(matrix[i][j]!=0){
       matrix[i][j]=0;
    }
    }
}
void makecol(vector<vector<int>>&matrix,int n,int j){
for(int i=0;i<n;i++){
    if(matrix[i][j]!=0){
       matrix[i][j]=0;
    }
}
}

    void setZeroes(vector<vector<int>>& matrix) {

        int r=matrix.size();
        int c=matrix[0].size();

        vector<int>row;
        vector<int>col;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(matrix[i][j]==0){
                 row.push_back(i);
                 col.push_back(j);
                }
            }
        }

        for(int i=0;i<row.size();i++){
            makerow(matrix,c,row[i]);
        
        }
        for(int i=0;i<row.size();i++){
            makecol(matrix,r,col[i]);
        }


    }
};