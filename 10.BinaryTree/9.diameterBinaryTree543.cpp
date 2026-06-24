#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int ans=0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0 ;
        }
        int l=height(root->left);
        int r=height(root->right);
        ans=max(l+r,ans);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
       return ans;
    }
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3); 
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<diameterOfBinaryTree(root)<<endl;
}