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
//tc = O(N)  SC = O(1)
Node* deleteMiddle(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    temp = head;
    for(int i=1; i<count/2; i++){
        temp = temp->next;
    }
    Node* t = temp->next;
    temp->next = temp->next->next;
    delete t;
    return head;
}
//tc = O(N)  SC = O(1)
Node* delete_Middle(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {1,2,3,4,5,6};
    Node* head1 = convertArr2LL(a);
    Node* head2 = convertArr2LL(b);
    head1 = delete_Middle(head1);
    print(head1);
    cout<<endl;
    head2 = delete_Middle(head2);
    print(head2);
    return 0;
}