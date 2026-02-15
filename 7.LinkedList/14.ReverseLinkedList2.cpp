#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        int i=1;
        while(curr!=NULL && i!=left){
            prev=curr;
            curr=curr->next;
            i++;
        }
        ListNode* pointstart=prev;
        ListNode* start=curr;
        prev=NULL;
        while(i!=right+1 && curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        start->next=curr;
        if(pointstart!=NULL){
            pointstart->next=prev;
        }
        else{
            return prev;
        }
        return head;
    }
int main() {
    ListNode* head = new ListNode(1);  
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int left = 2;
    int right = 4;
    ListNode* newHead = reverseBetween(head, left, right);
    ListNode* current = newHead;
    while (current != NULL) { 
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}