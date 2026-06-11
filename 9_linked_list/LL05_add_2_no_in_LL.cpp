/*
          Add Two Numbers in Linked List

head1:
+---+    +---+    +---+
| 2 | -> | 4 | -> | 6 | -> NULL
+---+    +---+    +---+

Number = 642


head2:
+---+    +---+    +---+
| 3 | -> | 8 | -> | 7 | -> NULL
+---+    +---+    +---+

Number = 783


        1
      642
    + 783
    -----
     1425


sumList (result):
+---+    +---+    +---+    +---+
| 5 | -> | 2 | -> | 4 | -> | 1 | -> NULL        Represents = 1425
+---+    +---+    +---+    +---+
  ^                
  | 
 head

//return head

*/



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
        Node* temp = new Node(a[i]);
        movers->next = temp;
        movers = temp;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* add2num(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummy = new Node(-1);
    Node* current = dummy;
    int carry = 0;
    while(t1!=NULL || t2!=NULL){
        int sum = 0;
        sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;
        Node* temp = new Node(sum%10);
        carry = sum/10;
        current->next = temp;
        current = current->next;
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* temp = new Node(carry);
        current->next = temp;
        current = current->next;
    }   
    return dummy->next;
}
int main(){
    vector<int> a ={3, 5};
    vector<int> b ={4, 5, 9, 9};
    Node* head1 = convertArr2LL(a);
    Node* head2 = convertArr2LL(b);
    Node* head = add2num(head1, head2);
    print(head);
}
