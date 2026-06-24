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
    vector<int> RightView(TreeNode* root) {
            vector<int> ans;
            if(root==NULL){
                return ans;
            }
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int s=q.size();
                for(int i=0;i<s;i++){
                    TreeNode*curr=q.front();
                    q.pop();
                    if(i==s-1){
                        ans.push_back(curr->val);
                    }
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }
            }
            return ans;
        }
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);  
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    vector<int> res=RightView(root);
    cout<<"Right View of Binary Tree is : ";
    for(int val:res){
        cout<<val<<" ";
    }
}