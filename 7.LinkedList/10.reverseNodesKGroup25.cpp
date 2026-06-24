#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        int count=0;
        while(count<k){
            if(temp==NULL){
                return head;
            }
            temp=temp->next;
            count++;
        }
        ListNode* prev=reverseKGroup(temp,k);
        temp=head;count=0;
        while(count<k){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            count++;
        }
        return prev;
    }

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

ListNode* createList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    
    ListNode* head = createList(arr);
    cout << "Original list: ";
    printList(head);
    
    head = reverseKGroup(head, k);
    cout << "After reversing in groups of " << k << ": ";
    printList(head);
    
    return 0;
}