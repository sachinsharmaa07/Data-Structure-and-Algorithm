 #include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};  
 TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* n=new TreeNode(val);
            return n;
        }
        if(root->val>val){
            root->left=insertIntoBST(root->left,val);
        }
        else{
           root->right= insertIntoBST(root->right,val);
        }
        return root;
    }
int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);   
    root->left->right=new TreeNode(3);
    int val=5;
    root=insertIntoBST(root,val);
    cout<<"BST after inserting "<<val<<": "<<endl;
    cout<<"Root: "<<root->val<<endl;
    cout<<"Left Child of Root: "<<root->left->val<<endl;
    cout<<"Right Child of Root: "<<root->right->val<<endl;
    cout<<"Left Child of Left Child: "<<root->left->left->val<<endl;
    cout<<"Right Child of Left Child: "<<root->left->right->val<<endl;
    cout<<"Left Child of Right Child: "<<root->right->left->val<<endl;
}  