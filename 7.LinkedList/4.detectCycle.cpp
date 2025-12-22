#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
  bool hasCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL && f->next!=NULL){//to avoid null pointer dereference
            s=s->next;//    slow pointer moves one step
            f=f->next->next;//fast pointer moves two steps
            if(f==s){//cycle detected
                return true;
            }
        }
        return false;
    }
}; 
 ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        bool isCycle=false;
        while(f!=NULL && f->next!=NULL){//to avoid null pointer dereference
            s=s->next;//    slow pointer moves one step
            f=f->next->next;//fast pointer moves two steps
            if(s==f){//cycle detected
                isCycle=true;
                break;
            }
        }
        if(isCycle){
            s=head;
            ListNode* prev=NULL;//to keep track of node before fast pointer
            while(s!=f){
                s=s->next;//moving both pointers one step at a time
                prev=f;//updating prev to current f before moving f
                f=f->next;//  moving f one step
            }
           prev->next=NULL; //to remove cycle
            return f;
        }
        else{
            return NULL;
        }

        
    }

int main(){
    ListNode* head=new ListNode(3);
    head->next=new ListNode(2);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(-4);
    // Creating a cycle for testing
    head->next->next->next->next=head->next;

    bool result=head->hasCycle(head);
    if(result){
        cout<<"Cycle detected in the linked list.\n";
    }
    else{
        cout<<"No cycle in the linked list.\n";
    }
    ListNode* cycleStart=detectCycle(head);
    if(cycleStart){
        cout<<"Cycle starts at node with value: "<<cycleStart->val<<"\n";
    }
    else{
        cout<<"No cycle detected, so no starting node.\n";
    }
    return 0;
}