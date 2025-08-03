class Solution {
public:
bool isPossible(vector<int>arr,int col,int target){
    int low=0;
    int high=col-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return true;
        }else if(arr[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return false;
    
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            if(isPossible(matrix[i],m,target)){
                return true;
            }
        }
        return false;
    }
};