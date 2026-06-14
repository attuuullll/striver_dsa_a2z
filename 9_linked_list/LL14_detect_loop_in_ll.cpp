/*
head
 |
 v

1 -> 2 -> 3 -> 4 -> 5 ----
          ^              |
          |              |
          9 <- 8 <- 7 <- 6

Cycle starts at node 3
*/



//tortoise and hare algorithm
//Note: For even-length linked lists, this returns the second middle node.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public: 
    Node(int x, Node* y){
        data = x;
        next = y;
    }

    public:
    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> a){
    Node* head = new Node(a[0]);
    Node* movers = head;
    for(int i = 1; i < a.size(); i++){
        Node* t = new Node(a[i]);
        movers->next = t;
        movers = t;
    }
    return head;
}
void print(Node* head){
    Node* t = head;
    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }

}
//TC = O(N log N)      SC = O(N)
bool detectLoop(Node* head){
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp){
        if(mpp.find(temp) != mpp.end()) return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}
//tortoise and hare
//TC = O(N)   SC = O(1)
bool DetectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        if(slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    if(DetectLoop(head))
        cout << "Loop Detected\n";
    else
        cout << "No Loop\n";

    return 0;
}