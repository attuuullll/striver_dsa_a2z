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
Node* reverseLL(Node * head){
    Node* prev = nullptr;
    Node* temp = head;
    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node* findKthNode(Node* temp, int k){
    k--;
    while(temp && k){
        temp = temp->next;
        k--;
    }
    return temp;
}
// TC = O(N)    SC = O(1)
Node* reverseNodes(Node* head, int k){
    Node* temp = head;
    Node* prevLast = NULL;
    while(temp){
        Node* kthNode = findKthNode(temp, k);
        if(kthNode == NULL){
            if(prevLast) prevLast->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        Node* newHead = reverseLL(temp);
        if(temp == head){
            head = newHead;
        }
        else{
            prevLast->next = newHead;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    Node* head = convertArr2LL(a);
    head = reverseNodes(head, 3);
    print(head);
    return 0;
}