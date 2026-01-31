#include<iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
 void kthLevel(TreeNode* root , int k){
    queue <TreeNode*> q;
    if(root==NULL){
        return ;
    }
    if(k==1){
            cout<<root->data<<" ";
            return;
        }
        kthLevel(root->left,k-1);
        kthLevel(root->right,k-1);

 }
 int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3); 
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    int k=3;
    kthLevel(root,k);
 }  