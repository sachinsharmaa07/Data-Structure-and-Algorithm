#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* prev=NULL;
        while(first !=NULL && second!=NULL){
            ListNode* third=second->next;
            second->next=first;
            first->next=third;
            if(prev!=NULL){
            prev->next=second;
            }
            else{
                head=second;
            }
            prev=first;
            first=third;
            if(first!=NULL){
                second=first->next;
            }
            else{
                second=NULL;
            }
        }
        if(first!=NULL){
            prev->next=first;
        }
        return head;
    }
    int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);        
    head->next->next->next=new ListNode(4);
    head=swapPairs(head);     
    ListNode* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}