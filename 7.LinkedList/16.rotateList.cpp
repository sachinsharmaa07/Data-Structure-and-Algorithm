 #include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}       
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};  

 ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        ListNode* tail=head;
        int count=1;
        while( tail->next!=NULL){
            count++;
            tail=tail->next;
        }
        k=k%count;
        if(k==0){
            return head;
        }
        tail->next=head;
        ListNode* newTail=head;
        for(int i=0;i<count-k-1;i++){
            newTail=newTail->next;
        }
        ListNode* h=newTail->next;
        newTail->next=NULL;
        return h;

    }
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);  
    head->next->next->next->next=new ListNode(5);
    int k=2;
    ListNode* res=rotateRight(head,k);
    cout<<"Rotated List is : ";
    while(res){
        cout<<res->val<<" ";
        res=res->next;
    }
}