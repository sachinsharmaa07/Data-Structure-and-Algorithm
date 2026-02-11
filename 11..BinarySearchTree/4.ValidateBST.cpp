#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 bool helper(TreeNode* root,TreeNode* min,TreeNode* max){
        if(root==NULL){
            return true;
        }
        if(max!=NULL && root->val>=max->val){
            return false;
        }
        if(min!=NULL && root->val<=min->val){
            return false;
        }
        return helper(root->left,min,root) &&
        helper(root->right,root,max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
int main(){
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    if(isValidBST(root)){
        cout<<"The binary tree is a valid binary search tree."<<endl;
    }else{
        cout<<"The binary tree is not a valid binary search tree."<<endl;
    }
    return 0;
}