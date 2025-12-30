#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// Function to find next greater element for each element in the vector
vector<int> NextGreater(vector<int> vec){
    stack<int> s;
    vector<int> ans(vec.size()); // Changed from ans[vec.size()] to ans(vec.size())
    
    // Traverse array from right to left
    for(int i=vec.size()-1; i>=0; i--){
        // Pop elements from stack that are <= current element
        while(s.size()>0 && s.top()<=vec[i]){
            s.pop();
        }
        // If stack is empty, no greater element exists
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            // Top of stack is the next greater element
            ans[i]=s.top();
        }
        // Push current element to stack
        s.push(vec[i]);
    }
    return ans;
}

int main(){
    vector<int> vec={2,1,5,3,4};
    vector<int> result=NextGreater(vec);
    // Print results
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}