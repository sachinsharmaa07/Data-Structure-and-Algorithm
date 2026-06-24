#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete temp;
        
    }
int main(){
    ListNode* head=new ListNode(4);
    head->next=new ListNode(5);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(9);
    ListNode* nodeToDelete=head->next; // Node with value 5
    deleteNode(nodeToDelete);
    cout<<"Linked List after deletion: ";
    ListNode* current=head;
    while(current!=NULL){
        cout<<current->val<<" ";
        current=current->next;
    }
    cout<<endl;
}
