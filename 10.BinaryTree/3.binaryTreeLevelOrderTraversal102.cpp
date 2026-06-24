#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
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
void levelOrderLC(Node * root){
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
        cout<<curr->data<<"   ";
    }
}
int main(){

    idx = -1;
    vector<int> Porder={10,20,40,-1,-1,50,-1,-1,30,60,-1,-1,70,-1,-1};
    Node* root=buildTree(Porder);
    cout<<"Level Order Traversal"<<endl;
    levelOrderLC(root);
}