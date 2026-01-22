#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next=NULL;
    }
};
class Queue{
    Node *head;
    Node* tail;
    public:
    Queue(){
        head=tail=NULL;
    }
    void push(int data){
        if(empty()){
            Node *newnode=new Node(data);
            head=newnode;
            tail=newnode;

        }
        else{
            Node* newnode=new Node(data);
            tail->next=newnode;
            tail=newnode;
        }

    }
    void pop(){
        Node* temp=head;
        head=head->next;
        delete temp;

    }
    bool empty(){
        return head==NULL;

    }
    int front(){
        if(empty()){
            cout<<"LL IS EMPTY";
            return -1;
        }
        else{
            return head->data;
        }
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // expect 10
    q.pop();
    cout << "Front after pop: " << q.front() << endl; // expect 20

    q.pop();
    q.pop();
    cout << "Is empty? " << (q.empty() ? "yes" : "no") << endl;

    return 0;
}