#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return 0;
        }

        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            ans.push_back(curr->val);
            
        }
    sort(ans.begin(), ans.end());
    int mini=INT_MAX;
    int n=ans.size();
    for(int i=0;i<n-1;i++){
        int temp=ans[i+1]-ans[i];
        mini=min(temp,mini);
    }
    return mini;
}
int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);

    cout<<minDiffInBST(root)<<endl;
}