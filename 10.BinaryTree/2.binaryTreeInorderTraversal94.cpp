#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void helper(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       helper(root,ans);
       return ans; 
    }
int main(){
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> result = inorderTraversal(root);
    for(int val : result){
        cout<< val << " ";
    }
    return 0;
}