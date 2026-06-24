#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *ptr;
    Node(int val){
        data=val;
        ptr=NULL;
    }
};
class List{
    Node *head;
    Node *tail;
    public:
    List(){
    head=tail=NULL;
    }
    void push_front(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        else{
            newnode->ptr=head;
            head=newnode;
        }
    }
    void printLL(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->ptr;
        }
        cout<<"\n";

    }
    void push_back(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        else{
            tail->ptr=newnode;
            tail=newnode;

        }
    }
    void pop_front(){
        if(head==NULL){
            cout<<"Linked List is already empty\n";
            return;
        }
        Node* temp= head;//new node
        head=head->ptr;//head = head->next for changing head;
        temp->ptr=NULL;//head connection break
        delete temp;//free memory
    }
    void pop_back(){
        if(head==NULL){
            return;
        }
        Node *temp=head;
        while(temp->ptr!=tail){
            temp=temp->ptr;
        }
        temp->ptr=NULL;
        delete tail;
        tail=temp;

    }
    void insert(int val, int pos){
        if(pos < 0){
            cout << "Error: Invalid position\n";
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        if(head == NULL){
            cout << "Error: List is empty and position > 0\n";
            return;
        }

        Node* temp = head;
        int count = 0;
        
        // Check if position exists in list
        while(count < pos-1 && temp != NULL){
            temp = temp->ptr;
            count++;
        }

        if(temp == NULL){
            cout << "Error: Position exceeds list length\n";
            return;
        }

        Node *newnode = new Node(val);
        newnode->ptr = temp->ptr;
        temp->ptr = newnode;
        
        // Update tail if inserting at end
        if(newnode->ptr == NULL){
            tail = newnode;
        }
    }
    int search(int x){
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==x){
                return idx;
            }
            temp=temp->ptr;
            idx++;

        }
        return -1;


    }
};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.printLL();
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(6);
    ll.printLL();
    ll.pop_front();
    ll.pop_front();
    ll.printLL();
    ll.pop_back();
    ll.pop_back();
    ll.printLL();
    ll.push_front(8);
    ll.push_front(9);
    ll.push_front(7);
    ll.push_front(6);
    ll.printLL();
    ll.insert(3,3);
    ll.insert(4,4);
    ll.insert(5,5);
    ll.printLL();
    int searchidx= ll.search(8);
    cout<<"the index of 8 is :"<<searchidx<<endl;

    
}