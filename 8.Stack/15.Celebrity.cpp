#include<iostream>
#include<unordered_map>
using namespace std;
int findCeleb(vector<vector<int>>& M, int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (M[a][b] == 1) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    int candidate = s.top();

    for (int i = 0; i < n; i++) {
            if (M[candidate][i] == 1 || M[i][candidate] == 0 && candidate!=i    ) {
                return -1;
            }
        
    }

    return candidate;
}
int main(){
    vector<vector<int>>M={{0,1,0},{0,0,0},{1,1,0}};
    int n=3;
    cout<<findCeleb(M,n);
}           
    