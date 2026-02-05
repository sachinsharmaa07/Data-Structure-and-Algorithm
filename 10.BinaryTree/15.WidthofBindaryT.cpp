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
 int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        int maxW=0;
        q.push({root,0});
        while(!q.empty()){
            int currLevelSize=q.size();
            unsigned long long startIdx=q.front().second;
            unsigned long long endIdx=q.back().second;
            maxW=max(maxW,(int)(endIdx-startIdx+1));
            for(int i=0;i<currLevelSize;i++){
                auto curr=q.front();
                q.pop();
                if(curr.first->left){ 
                    q.push({curr.first->left,curr.second*2+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right,curr.second*2+2});
                }
            }

        }
        return maxW;
    }
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(9);
    cout<<"Width of Binary Tree is : "<<widthOfBinaryTree(root)<<endl;
}