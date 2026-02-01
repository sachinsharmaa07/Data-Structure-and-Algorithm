#include<iostream>
using namespace std;
#include<vector>
struct TreeNode {
    int data;
    TreeNode *left; 
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

int search(vector<int>& inorder ,int l,int r,int x){
        for(int i=l;i<=r;i++){
            if(inorder[i]==x){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder ,int &preidx,int l,int r){
        if(l>r){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[preidx++]);
        int inidx=search(inorder,l,r,preorder[preidx-1]);
        root->left=helper(preorder,inorder,preidx,l,inidx-1);
        root->right=helper(preorder,inorder,preidx,inidx+1,r);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx=0;
        return helper(preorder,inorder,preidx,0,preorder.size()-1);
    }
int main(){ 
    vector<int>preorder={1,2,4,5,3,6,7};
    vector<int>inorder={4,2,5,1,6,3,7};
    TreeNode* root=buildTree(preorder,inorder);
}  