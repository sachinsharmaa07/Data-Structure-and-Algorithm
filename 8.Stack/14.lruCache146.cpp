#include<iostream>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    int limit;

    // Add node right after head
    void addNode(Node* newnode) {
        Node* oldnext = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = oldnext;
        oldnext->prev = newnode;
    }

    // Delete given node
    void delNode(Node* oldnode) {
        Node* oldprev = oldnode->prev;
        Node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
         tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->value;

        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if (m.size() == limit) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
        }

        Node* newnode = new Node(key, value);
        addNode(newnode);
        m[key] = newnode;
    }
};
int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl; // returns 1
    obj->put(3,3);           // evicts key 2
    cout<<obj->get(2)<<endl; // returns -1 (not found)
    obj->put(4,4);           // evicts key 1
    cout<<obj->get(1)<<endl; // returns -1 (not found)
    cout<<obj->get(3)<<endl; // returns 3
    cout<<obj->get(4)<<endl; // returns 4
}