#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
int data;
Node* left;
Node *right;
Node(int data){
this->data=data;
left=right=NULL;
}
};
static int idx=-1;
Node *buildTree(vector<int> & preOrder){
    idx++;
    if(idx >= (int)preOrder.size() || preOrder[idx]==-1){
        return NULL;
    }
    Node* root=new Node(preOrder[idx]);
    root->left=buildTree(preOrder);
    root->right=buildTree(preOrder);
    return root;
}
void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    cout<<endl;
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<endl;
}
void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}

int main(){
    idx = -1;
    vector<int> Porder={10,20,40,-1,-1,50,-1,-1,30,60,-1,-1,70,-1,-1};
    Node* root=buildTree(Porder);
    cout<<"Preorder Traversal"<<endl;
    preOrder(root);
    cout<<"PostOrder Traversal"<<endl;
    postOrder(root);
    cout<<"Inorder Traversal"<<endl;
    inOrder(root);
    return 0;
}