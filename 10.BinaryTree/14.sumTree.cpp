#include<iostream>
using namespace std;
#include<vector>
struct TreeNode {
    int val;
    TreeNode *left; 
    TreeNode *right;        
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root,string path,vector<string>& ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }
        if(root->left){
            helper(root->left,path+"->"+to_string(root->left->val),ans);
        }
        if(root->right){
            helper(root->right,path+"->"+to_string(root->right->val),ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> ans;
       string path=to_string(root->val);
       helper(root,path,ans); 
       return ans;
    }
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3); 
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<string> paths=binaryTreePaths(root);
    for(const string &s:paths){
        cout<<s<<"\n";
    }
}