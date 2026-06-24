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
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> levels;
    if (root == NULL) {
        return levels;
    }

    queue<Node*> que;
    que.push(root);

    while (!que.empty()) {
        int count = que.size();
        vector<int> current;
        current.reserve(count);

        for (int i = 0; i < count; i++) {
            Node* temp = que.front();
            que.pop();

            current.push_back(temp->data);
            if (temp->left != NULL) {
                que.push(temp->left);
            }
            if (temp->right != NULL) {
                que.push(temp->right);
            }
        }

        levels.push_back(current);
    }

    return levels;
}

int main(){
    idx = -1;
    vector<int> Porder={10,20,40,-1,-1,50,-1,-1,30,60,-1,-1,70,-1,-1};
    Node* root=buildTree(Porder);
    vector<vector<int>> levels = levelOrder(root);
    for (const auto& lvl : levels) {
        for (int val : lvl) {
            cout << val << " ";
        }
        cout << endl;
    }

}