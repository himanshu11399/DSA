/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode*root,vector<int>&arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    vector<int> search(vector<int>&arr,int target){
        int floor=-1;
        int ceil=-1;
        int low=0;
        int high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                floor=ceil=arr[mid];
                break;
            }else if(arr[mid]>target){
                ceil=arr[mid];
                high=mid-1;
            }else{
                floor=arr[mid];
                low=mid+1;
            }
        }

        return {floor,ceil};
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ans;
        vector<int>arr;
        inorder(root,arr);
        for(int i=0;i<queries.size();i++){
            ans.push_back(search(arr,queries[i]));
        }
        return ans;
    }
};