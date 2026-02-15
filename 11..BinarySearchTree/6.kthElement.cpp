#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static int count=0;
int ans=-1;
void helper(TreeNode* root,int k){
        if(!root){
            return;
        }
        if(root->left){
        helper(root->left,k);
        }
        ::count++;
        if(::count==k){
            ans=root->val;
            return;
        }
        if(root->right){
        helper(root->right,k);
        }
    }

int kthSmallest(TreeNode* root, int k) {
    helper(root,k);
    return ans;
}
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->right=new TreeNode(4);
    root->left->right=new TreeNode(2);
    int k=1;
    int kthSmallestElement=kthSmallest(root,k);
    cout<<"The "<<k<<"-th smallest element in the binary search tree is: "<<kthSmallestElement<<endl;
    return 0;  }    