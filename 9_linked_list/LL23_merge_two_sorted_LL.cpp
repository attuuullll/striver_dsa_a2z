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
//brute force
// TC = O((N+M) log(N+M))   SC = O(N+M)
Node* mergeLists(Node* head1, Node* head2){
    vector<int> arr;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1){
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2){
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }
    sort(arr.begin(), arr.end());
    return convertArr2LL(arr);
}
//optimal
// TC = O(N + M)    SC = O(1)
Node* mergeLists(Node* head1, Node* head2){
    Node dummy(-1);
    Node* temp = &dummy;
    while(head1 && head2){
        if(head1->data <= head2->data){
            temp->next = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if(head1) temp->next = head1;
    else temp->next = head2;
    return dummy.next;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    Node* head = convertArr2LL(a);
    print(head);
    return 0;
}