// use stack(LIFO)
//using swap next and back



#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int x, Node* y, Node* z){
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

//using stack tc:O(2n)  sc:O(n)
Node* reverse_DLL(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp){
        temp ->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
Node* reverse_DLL_swap(Node* head){
    Node* current = head;
    while(current){
        if(current->next == nullptr) head = current;
        Node* last = current->back;
        current->back = current->next;
        current->next = last;

        current = current->back;
         
    }
    return head;
    
}
int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(a);

    head = reverse_DLL_swap(head);
    print(head);
    return 0;
}