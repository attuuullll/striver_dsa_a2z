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
Node* findNthNode(Node* head, int n){
    while(--n){
        head = head->next;
    }
    return head;
}
// TC = O(N)    SC = O(1)
Node* rotateRight(Node* head, int k){
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    int len = 1;
    Node* tail = head;

    while(tail->next){
        len++;
        tail = tail->next;
    }

    k = k % len;

    if(k == 0)
        return head;

    tail->next = head;

    Node* newLastNode = findNthNode(head, len - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}
int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = convertArr2LL(a);
    head = rotateRight(head, 3);
    print(head);
    return 0;
}