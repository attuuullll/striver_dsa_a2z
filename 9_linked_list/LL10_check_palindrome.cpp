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
bool palindrome_or_not(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(st.top()==temp->data){
            st.pop();
            temp = temp->next;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> a = {1, 2, 3, 2, 1};
    Node* head = convertArr2LL(a);
    cout<<palindrome_or_not(head);
    return 0;
}