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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int preindex=0;
       int n=preorder.size();
      TreeNode*ans=solve(preorder,inorder,preindex,0,n-1);
      return ans;  
    }
    private:
    TreeNode*solve(vector<int>preorder,vector<int>inorder,int& index,int start,int end){
        int n=preorder.size();
        if(index>=n || start>end)   return NULL;
        int current=preorder[index];
        index++;
        TreeNode*root=new TreeNode(current);
        int pos=find(inorder,current);
        
        root->left=solve(preorder,inorder,index,start,pos-1);
        root->right=solve(preorder,inorder,index,pos+1,end);
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