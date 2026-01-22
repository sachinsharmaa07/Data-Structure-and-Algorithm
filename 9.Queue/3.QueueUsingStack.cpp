#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }

        
    }
    
    int pop() {
        int z=s1.top();
        s1.pop();
        return z;

    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl; // expect 10
    cout << "Pop: " << q.pop() << endl; // expect 10
    cout << "Front after pop: " << q.peek() << endl; // expect 20
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl; // expect No

    return 0;
}   