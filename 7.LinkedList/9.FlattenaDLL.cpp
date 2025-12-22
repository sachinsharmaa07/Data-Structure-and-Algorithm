#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
        child=nullptr;
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
        if(head == tail){  // only one node
            head = tail = nullptr;
        }
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;                          
        }
        cout << endl;
    }
    Node* getHead(){
        return head;
    } 
    void addchild(Node* parent, Node* child){
        if(parent==nullptr){
            return;
        }
        parent->child=child;
    }   

};

Node* flatten(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* curr = head;
    while(curr != nullptr){
        if(curr->child != nullptr){
            Node* next = curr->next;
            Node* child = flatten(curr->child);
            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;
            // Traverse to the end of the flattened child list
            Node* temp = child;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            // Connect the end of the child list to the next node
            temp->next = next;
            if(next != nullptr){
                next->prev = temp;
            }
        }
        curr = curr->next;
    }
    return head;
}
int main(){
    doublyLL dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.addchild(dll.getHead()->next, new Node(7));
    dll.addchild(dll.getHead()->next->child, new Node(8));
    dll.getHead()->next->child->child->next=new Node(9);
    dll.push_back(4);
    dll.display();
    dll.pop_front();
    dll.addchild(dll.getHead(), new Node(5));
    dll.addchild(dll.getHead()->child, new Node(6)); 
    dll.display();
    Node* flattendll = flatten(dll.getHead());
    while(flattendll != nullptr){
        cout << flattendll->data << " ";
        flattendll = flattendll->next;
    }   
    return 0;
}