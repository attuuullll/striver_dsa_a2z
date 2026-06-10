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









Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;   
    return head;
}
Node* deleteTail(Node* head){
    if(head == nullptr)
        return nullptr;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deleteKthElement(Node* head, int k){
    if(head == nullptr) return head;
    if(k==1){
        return deleteHead(head);
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
//my method
// Node* deleteKthIndex(Node* head, int k){
//     if(head == nullptr) return head;
//     if(k==1){
//         return deleteHead(head);
//     }
//     Node* temp = head;
//     for(int i = 1;  i < k-1 && temp != nullptr; i++){
//         temp = temp->next;
//     }
//     if(temp == nullptr || temp->next == nullptr) return head;
//     Node* tempoo = temp->next;
//     temp->next = temp->next->next;
//     delete tempoo;
//     return head;
// }
Node* deleteElement(Node* head, int val){
    if(head == nullptr) return head;
    if(head->data == val){
        return deleteHead(head);
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data==val){
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val);
    temp->next = head;    
    return temp; 
}
Node* insertTail(Node* head, int val){
    Node* temp = new Node(val);
    if(head == nullptr) return temp;
    Node* temp1 = head;
    while(temp1->next!=nullptr){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}
Node* insert_Kth_Position(Node* head, int val, int k){
    if(k<=0) return head;
    if(k == 1){
        return insertHead(head, val);
    }
    Node* temp1 = head;
    for(int i = 1; i<k-1 && temp1 != nullptr; i++){
        temp1 = temp1->next;
    }
    if(temp1 == nullptr) return head;
    Node* temp = new Node(val);
    temp->next = temp1->next;
    temp1->next = temp;
    return head;
}
Node* insert_before_element(Node* head, int val, int element){
    if(head == nullptr) return head;
    if(head->data == element)  return insertHead(head,val);
    
    Node* temp = head;
    Node* prev = NULL;
    while(temp != nullptr && temp->data != element){
        prev = temp;
        temp = temp->next;
    }
    if(temp == nullptr) return head;
    Node* temp1 = new Node(val);
    temp1->next = temp;
    prev->next = temp1;
    return head;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2LL(a);

    //delete head
    //head = deleteHead(head);
    //print(head);

    //delete tail
    // head = deleteTail(head);
    // print(head);
    
    //delete kth element
    // head = deleteKthElement(head, 3);
    // print(head);

    //delete any element
    // head = deleteElement(head, 3);
    // print(head);

    //insert at head
    // head = insertHead(head, 0);
    // print(head);

    // insert at kth position
    // insert_Kth_Position(head, 10, 3);
    // print(head);
    
    
    return 0;
}