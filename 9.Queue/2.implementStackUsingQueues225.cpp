#include <queue>
using namespace std;
#include<iostream>
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int z=q1.front(); 
        q1.pop();
        return z;

    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // expect 30
    cout << "Pop: " << st.pop() << endl; // expect 30
    cout << "Top after pop: " << st.top() << endl; // expect 20
    cout << "Is empty: " << (st.empty() ? "Yes" : "No") << endl; // expect No

    return 0;
}