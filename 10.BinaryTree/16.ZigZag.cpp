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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if(root==NULL){
                return ans;
            }
            bool L2R=true;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int s=q.size();
                vector<int>level(s);
                for(int i=0;i<s;i++){
                    TreeNode*curr=q.front();
                    q.pop();
                    int idx=i;
                    if(!L2R){
                        idx=s-i-1;
                    }
                    level[idx]=curr->val;
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }
                ans.push_back(level);
                L2R=!L2R;

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
    vector<vector<int>> res=zigzagLevelOrder(root);
    cout<<"ZigZag Level Order Traversal of Binary Tree is : "<<endl;
    for(const auto& level:res){
        for(int val:level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}   