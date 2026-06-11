/*
           Odd Even Linked List

Original List:

head
 |
 v
+---+    +---+    +---+    +---+    +---+    +---+
| 1 | -> | 3 | -> | 4 | -> | 2 | -> | 5 | -> | 6 | -> NULL
+---+    +---+    +---+    +---+    +---+    +---+

Position:
  1        2        3        4        5        6

Odd Positions:   1 -> 4 -> 5
Even Positions:  3 -> 2 -> 6

Result:

+---+    +---+    +---+    +---+    +---+    +---+
| 1 | -> | 4 | -> | 5 | -> | 3 | -> | 2 | -> | 6 | -> NULL
+---+    +---+    +---+    +---+    +---+    +---+
*/




//use list (FIFO)




#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node* back;

    public:
    Node(int x, Node* y, Node*z){
        data = x;
        next = y;
        back = z;
    }

    public:
    Node(int x){
        data = x;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2LL(vector<int> a){
    if(a.empty()) return nullptr;
    Node* head = new Node(a[0]);
    Node* movers = head;
    for(int i = 1; i < a.size(); i++){
        Node* odd = new Node(a[i],nullptr,movers);
        movers->next = odd;
        movers = odd;
    }
    return head;
}
void print(Node* head){
    Node* odd = head;
    while(odd){
        cout<<odd->data<<" ";
        odd = odd->next;
    }
}


//method 1 using list
Node* oddEven(Node* head){
    if(head == nullptr) return head;
    Node* odd = head;
    list<int> l;
    while(odd ){
        l.push_back(odd->data);
        odd = (odd->next) ? odd->next->next : nullptr;
    }
    odd = head->next;
    while(odd ){
        l.push_back(odd->data);
        odd = (odd->next) ? odd->next->next : nullptr;
    }
    odd = head;
    while(odd){
        odd->data = l.front();
        l.pop_front();
        odd = odd->next;
    }
    return head;
}
Node* Odd_Even(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main(){
    vector<int> a = {2, 3, 1, 4, 5, 6};
    Node* head = convertArr2LL(a);
     
    head = Odd_Even(head);
    print(head);
    return 0;
}