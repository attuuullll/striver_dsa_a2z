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
//tc:O(N + M)  sc:O(N)
Node* intersection(Node* head1, Node* head2){
    Node* t = head1;
    map<Node*, int> mpp;
    while(t){
        mpp[t] = 1;
        t = t->next;
    }
    t = head2;
    while(t){
        if(mpp.find(t)!=mpp.end()){
            return t;
        }
        t = t->next;
    }
    return NULL;
}

//tc:O(N + M) sc:O(1)
Node* Intersection(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    int l1=0, l2=0;
    while(t1){
        l1++;
        t1 = t1->next;
    }
    while(t2){
        l2++;
        t2 = t2->next;
    }
    t1 = head1;
    t2 = head2;
    if(l1>l2){
        l1 = l1-l2;
        for(int i=0; i<l1; i++){
            t1 = t1->next;
        }
    }
    else{
        l2 = l2-l1;
        for(int i=0; i<l2; i++){
            t2 = t2->next;
        }
    }
    while(t1 && t2){
        if(t1 == t2){
            return t1;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return NULL;
}
//tc : O(N + M)   sc: O(1)
Node* INTERSECTION(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != t2){
        t1 = (t1==NULL)?head2:t1->next;
        t2 = (t2==NULL)?head1:t2->next;
    }
    return t1;
}
int main(){

    // Common part
    Node* common = new Node(8);
    common->next = new Node(10);

    // List 1: 3 -> 6 -> 9 -> 8 -> 10
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;

    // List 2: 4 -> 8 -> 10
    Node* head2 = new Node(4);
    head2->next = common;

    Node* ans = INTERSECTION(head1, head2);

    if (ans)
        cout << "Intersection at node: " << ans->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}