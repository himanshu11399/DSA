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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
       int n=postorder.size();
       int preindex=n-1;
      TreeNode*ans=solve(postorder,inorder,preindex,0,n-1);
      return ans;  
    }
    private:
    TreeNode*solve(vector<int>postorder,vector<int>inorder,int& index,int start,int end){
        int n=postorder.size();
        if(index<0 || start>end)   return NULL;
        int current=postorder[index];
        index--;
        TreeNode*root=new TreeNode(current);
        int pos=find(inorder,current);

         root->right=solve(postorder,inorder,index,pos+1,end);
         root->left=solve(postorder,inorder,index,start,pos-1);
       
        return root;

    }
    int find(vector<int>arr,int element){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==element){
                return i;
            }
        }
        return -1;
    }
};