#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class circularLL {
    Node* head;
    Node* tail;
public:
    circularLL() {
        head=tail=NULL;
    }
    void push_front(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            tail->next=head;
        }
        else{
            newnode->next=head;
            head=newnode;
            tail->next=newnode;
        }}
        void push_back(int val){
            Node* newnode=new Node(val);
            if(head==nullptr){
                head=tail=newnode;
                tail->next=head;
            }
            else{
                newnode->next=head;
                tail->next=newnode;
                tail=newnode;
            }

        }
        void pop_front(){
            if(head==nullptr){
                return;
            }
            if(head==tail){
                delete head;
                head=tail=nullptr;
            }
            else{
                Node* temp=head;
                head=head->next;
                tail->next=head;
                delete temp;
            }
        }
        void pop_back(){
            if(head==nullptr){
                return;
            }
            if(head==tail){
                delete head;
                head=tail=nullptr;
            }
            else{
                Node* temp=tail;
                Node* prev=head;
                while(prev->next!=tail){
                    prev=prev->next;
                }
                tail=prev;
                tail->next=head;  // maintain circularity
                delete temp;
            }}
    
};