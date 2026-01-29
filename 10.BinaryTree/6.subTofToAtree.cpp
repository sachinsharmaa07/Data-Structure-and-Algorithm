#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p==q;
        }
        bool isLeftSame=isSameTree(p->left,q->left);
        bool isRightSame=isSameTree(p->right,q->right);
        return isLeftSame && isRightSame && p->val==q->val;
    }
bool subTree(TreeNode *root ,TreeNode* subRoot){
    if(subRoot==NULL){
        return true;
    }
    if(root==NULL){
        return false;
    }
    if(root->val==subRoot->val && isSameTree(root,subRoot)){
        return true;
    }
    bool left=subTree(root->left,subRoot);
    bool right=subTree(root->right,subRoot);
    return left || right;
}
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(4);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(2);
    root->left->right->left=new TreeNode(0);

    TreeNode* subRoot=new TreeNode(4);
    subRoot->left=new TreeNode(1);
    subRoot->right=new TreeNode(2);

    cout<<subTree(root,subRoot)<<endl;
}