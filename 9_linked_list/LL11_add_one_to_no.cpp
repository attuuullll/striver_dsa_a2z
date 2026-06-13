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
Node* reverseLL(Node* head){
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
//tc: O(3N) sc:O(1) 
Node* addOne(Node* head){
    int carry = 1;
    head = reverseLL(head);
    Node* temp = head;
    while(temp){
        int sum = temp->data + carry;
        temp->data = sum%10;
        carry = sum/10;
        if(carry == 0) break;
        if(temp->next==NULL && carry){
			temp->next=new Node(carry);
			carry=0;
			break;
		}
        temp = temp->next;
    }
    head = reverseLL(head);
    return head;
}
//reccursion
Node* add_one( Node* head,int carry){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = add_one(head->next, carry);
    Node* temp = head->next;
    if(carry == 0) return temp;
    int sum = temp->data + carry;
    temp->data = sum%10;
    carry = sum/10;
    return head;
}
int main(){
    vector<int> a = {9, 9, 9};
    Node* head = convertArr2LL(a);
    head = add_one(head, 1);
    print(head);
    return 0;
}