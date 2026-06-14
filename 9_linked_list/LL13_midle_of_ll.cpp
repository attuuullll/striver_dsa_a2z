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
//tc: O(N) sc:O(1)
Node* middle(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    temp = head;
    for(int i =1; i<((count/2)+1); i++){
        temp = temp->next;
    }
    return temp;
}
//tortois and hare algorithm
// TC = O(N)
// SC = O(1)
Node* findMiddle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {1,2,3,4,5,6};
    Node* head1 = convertArr2LL(a);
    Node* head2 = convertArr2LL(b);
    head1 = findMiddle(head1);
    cout<<head1->data<<endl;
    head2 = findMiddle(head2);
    cout<<head2->data<<endl;
    return 0;
}