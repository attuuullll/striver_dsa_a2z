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
//tc: O(2N) sc: O(1)
Node* sorrt(Node* head){
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    Node* temp = head;
    while(temp){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1)cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(cnt0>0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1>0){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}
Node* sortList(Node* head){
    Node* zeroHead = new Node(0);
    Node* oneHead = new Node(1);
    Node* twoHead = new Node(2);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;
    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next)? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    head = zeroHead->next;
    delete oneHead;
    delete twoHead;
    delete zeroHead;
    return head;
}
int main(){
    vector<int> a = {0, 0, 1, 0, 2, 2, 1, 0, 2};
    Node* head = convertArr2LL(a);

    head = sortList(head);
    print(head);
    return 0;
}