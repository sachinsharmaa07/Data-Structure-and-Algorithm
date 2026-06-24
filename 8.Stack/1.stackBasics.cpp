#include <iostream>
#include <vector>
using namespace std;
class Stack{
    vector<int> arr;
    public:
    void push(int x){
        arr.push_back(x);
    }
    void pop(){
        if(!arr.empty()){
            arr.pop_back();
        }
    }
    int top(){
        if(!arr.empty()){
            return arr.back();
        }
        return -1; // or throw an exception
    }
    bool isEmpty(){
        return arr.empty();
    }
    int size(){
        return arr.size();
    }
};
class StackLL{
    struct Node{
        int data;
        Node* next;
        Node(int x): data(x), next(nullptr) {}
    };
    Node* head;
    int count;
    public:
    StackLL(): head(nullptr), count(0) {}
    void push(int x){
        Node* newNode=new Node(x);
        newNode->next=head;
        head=newNode;
        count++;
    }
    void pop(){
        if(head!=nullptr){
            Node* temp=head;
            head=head->next;
            delete temp;
            count--;
        }
    }
    int top(){
        if(head!=nullptr){
            return head->data;
        }
        return -1; // or throw an exception
    }
    bool isEmpty(){
        return head==nullptr;
    }
    int size(){
        return count;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    cout<<"Top element: "<<s.top()<<endl; // Output: 20     
    s.pop();
    cout<<"Top element after pop: "<<s.top()<<endl; // Output: 10
    cout<<"Is stack empty? "<<(s.isEmpty() ? "Yes" : "No")<<endl; // Output: No
    cout<<"Stack size: "<<s.size()<<endl; // Output: 1
    StackLL sll;
    sll.push(30);
    sll.push(40);
    cout<<"Top element of StackLL: "<<sll.top()<<endl; // Output:   40     
    sll.pop();
    cout<<"Top element of StackLL after pop: "<<sll.top()<<endl; //
    cout<<"Is StackLL empty? "<<(sll.isEmpty() ? "Yes" : "No")<<endl; // Output: No
    cout<<"StackLL size: "<<sll.size()<<endl; // Output: 1
    return 0;

}