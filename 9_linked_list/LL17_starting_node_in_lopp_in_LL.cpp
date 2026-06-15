#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x, Node* y){
        data = x;
        next = y;
    }

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
        cout << t->data << " ";
        t = t->next;
    }
}
// TC = O(N log N)   SC = O(N) 
Node* startNode(Node* head){
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp){
        if(mpp.find(temp) != mpp.end()) return temp;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}
//TC = O(N)  SC = O(1)
Node* start_Node(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(fast == NULL || fast->next == NULL) return NULL;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;
    cout<<start_Node(head)->data;
    return 0;
}