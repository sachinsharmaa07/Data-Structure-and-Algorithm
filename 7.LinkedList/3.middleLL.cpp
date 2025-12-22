#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        int y;
        if(count%2==0){
            y=count/2;
        }
        else{
            y=count/2;y++;
        }
        for(int i=0;i<y;i++){
            temp=temp->next;
        }
        return temp;
        
    }
    ListNode* middleNodeSlowFast(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);                     
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5); 
    head->next->next->next->next->next=new ListNode(6);
    ListNode* mid=middleNode(head);
    ListNode* midSlowFast=middleNodeSlowFast(head);
    cout<<mid->val<<"\n";
    cout<<midSlowFast->val<<"\n";
    return 0;
}