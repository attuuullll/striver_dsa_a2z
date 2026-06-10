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

Node* convertArr2DLL(vector<int> a){
    if(a.empty()) return nullptr;
    Node* head = new Node(a[0]);
    Node* movers = head;
    for(int i = 1; i < a.size(); i++){
        Node* temp = new Node(a[i],nullptr,movers);
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
Node* deleteHead(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp ->next = nullptr;
    delete temp;
    return head;
}
Node* deleteTail(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next != nullptr){
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    // temp->back = nullptr;    ye line jruri nhi waise bhi temp delete hone wala hai
    delete temp;
    return head;
}
Node* delete_kth_ele(Node* head, int k){
    if(head==nullptr) return nullptr;
    if(k==1){
        return deleteHead(head);
    }
    Node* temp = head;
    for(int i = 1; i < k && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr ) return head;
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front != nullptr){
        front->back = prev;
    }
    prev->next = front;
    delete temp;
    return head;
    
}
Node* deleth_element(Node* head, int element){
    if(head == nullptr) return nullptr;
    if(head->data == element){
        return deleteHead(head);
    }
    Node* temp = head;
    while(temp != nullptr && temp->data != element){
        temp = temp->next;
    }
    if(temp == nullptr) return head;
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front!=nullptr){
        front->back = prev;
    }
    prev->next = front;
    delete temp;
    return head;
}
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head, nullptr);
    if(head != nullptr){
        head->back = temp;
    }
    return temp;
}
Node* insertTail(Node* head, int val){  
    Node* temp = new Node(val);
    if(head == nullptr) return temp;
    Node* temp1 = head;
    while(temp1->next != nullptr){
        temp1 = temp1->next;
    }
    temp->back = temp1;    
    temp1->next = temp;
    return head;
}
Node* insert_Kth_Position(Node* head , int k, int val){
    if(k<=0) return head;
    if(k==1){
        return insertHead(head, val);
    }
    Node* temp1 = head;
    for(int i=1; i<k-1 && temp1 != nullptr; i++){
        temp1 = temp1->next;
    }
    if(temp1 == nullptr) return head;
    Node* temp = new Node(val);
    temp-> next = temp1->next;
    if(temp1->next != nullptr){
        temp->next->back= temp;
    }
    temp->back = temp1;
    temp1->next = temp;
    return head;
}
void insert_before_node(Node* node, int val){
    Node* prev = node->back;
    Node* NewNode = new Node(val, node, prev);
    prev->next = NewNode;
    node->back = NewNode;
}
int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2DLL(a);

    // delete head
    // head = deleteHead(head);
    // print(head);

    //delete tail
    // head = deleteTail(head);
    // print(head);

    //delete kth element
    // head = delete_kth_ele(head, 3);
    // print(head);

    //delete element
    // head = deleth_element(head, 4);
    // print(head);

    //insert element
    // head = insertHead(head, 4);
    // print(head);

    //insert tail
    // head = insertTail(head, 7);
    // print(head);

    //insert at kth position
    // head = insert_Kth_Position(head, 3, 8);
    // print(head);
    
    //insert before node;
    insert_before_node(head->next , 100);
    print(head);

    return 0;
}
