#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
void bottomView(TreeNode *root){
    if(root==NULL){
        return;
    }
    queue <pair<TreeNode*,int>>q;
    map<int,int>m;
    q.push({root,0});
    while(!q.empty()){
        TreeNode* curr=q.front().first;
        int HD=q.front().second;
        q.pop();
        m[HD]=curr->data;
        if(curr->left!=NULL){
            q.push({curr->left,HD-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,HD+1});
        }
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }

   
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3); 
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    bottomView(root);
}

   