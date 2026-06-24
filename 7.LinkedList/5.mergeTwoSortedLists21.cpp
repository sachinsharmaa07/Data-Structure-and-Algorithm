#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1==NULL or h2==NULL){
            return h1==NULL?h2:h1;
        }
        if(h1->val<=h2->val){
            h1->next=mergeTwoLists(h1->next,h2);
            return h1;
        }
        else{
            h2->next=mergeTwoLists(h1,h2->next);
            return h2;
        }
        
    }
    int main(){
        ListNode* head1=new ListNode(1);
        head1->next=new ListNode(3);
        head1->next->next=new ListNode(5);

        ListNode* head2=new ListNode(2);
        head2->next=new ListNode(4);
        head2->next->next=new ListNode(6);

        ListNode* mergedHead=mergeTwoLists(head1,head2);
        cout<<"Merged Sorted Linked List: ";
        while(mergedHead!=NULL){
            cout<<mergedHead->val<<" ";
            mergedHead=mergedHead->next;
        }
        cout<<endl;
        return 0;
    }
