#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x
), left(left), right(right) {}
}; 
TreeNode* helper(vector<int>& nums ,int l ,int r){
        if(l>r){
            return NULL;
        }
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,l,mid-1);
        root->right=helper(nums,mid+1,r);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
int main(){ 
    vector<int> nums={-10,-3,0,5,9};
    TreeNode* root=sortedArrayToBST(nums);
    cout<<"Root value: "<<root->val<<endl;
    cout<<"Left child of root: "<<root->left->val<<endl;
    cout<<"Right child of root: "<<root->right->val<<endl;
    return 0;
}