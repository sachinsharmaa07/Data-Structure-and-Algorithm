#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};  

class doublyLL{
    Node* head;
    Node* tail;
public:
    doublyLL(){
        head = tail = nullptr;
    }
    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = tail = newnode;
            return;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    void push_back(int val){
        Node*newnode=new Node(val);
        if(tail == nullptr){
            head = tail = newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    void pop_front(){
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        if(head == tail){  // only one node
            head = tail = nullptr;
        }
        else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    void pop_back(){
        if(tail == nullptr){
            return;
        }
        Node* temp = tail;
        if(head == tail){
            head = tail = nullptr;
        }
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

};

int main(){
    doublyLL dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_front(5);
    dll.pop_front();
    dll.pop_back();
    return 0;
    
}
