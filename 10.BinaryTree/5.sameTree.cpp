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
int main(){
    TreeNode* p=new TreeNode(1);
    p->left=new TreeNode(2);   
    p->right=new TreeNode(3);
    TreeNode* q=new TreeNode(1);
    q->left=new TreeNode(2);   
    q->right=new TreeNode(3);
    cout<<isSameTree(p,q);
}