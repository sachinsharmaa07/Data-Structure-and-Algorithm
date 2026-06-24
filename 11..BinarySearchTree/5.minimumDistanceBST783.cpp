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

int minDiffInBST(TreeNode* root) {
    static TreeNode* prev = NULL;
    int ans = INT_MAX;
    if(root == NULL){
        return INT_MAX;
    }
    if(root->left){
        int leftMin = minDiffInBST(root->left);
        ans = std::min(ans, leftMin);
    }
    if(prev != NULL){
        ans = std::min(ans, root->val - prev->val);
    }
    prev = root;
    if(root->right){
        int rightMin = minDiffInBST(root->right);
        ans = std::min(ans, rightMin);
    }
    return ans;
}
int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    int minDiff=minDiffInBST(root);
    cout<<"The minimum difference between any two nodes in the binary search tree is: "<<minDiff<<endl;
    return 0;  }