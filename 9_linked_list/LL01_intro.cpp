#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public: 
    Node(int x, Node*y){
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
        movers = temp;  // or movers = movers->next
    }
    return head;
}
int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
    }
    return 0;
}
int main(){
    vector<int> a = {2,5,8,7};
    Node* head = convertArr2LL(a);
    cout<<head->data<<endl;;

    // traverse
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    //length
    cout<<length(head)<<endl;;

    //check if present
    cout<<checkIfPresent(head, 2)<<endl;;
    return 0;
}