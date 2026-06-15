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
//TC = O(N log N) using map
//TC = O(N) using unordered_map
//SC = O(N)
int lengthOfLoop(Node* head){
    Node* temp = head;
    Node* t = head;
    map<Node*, int> mpp;
    int count = 0;
    while(temp && mpp.find(temp)==mpp.end()){
        mpp[temp] = 1;
        count++;
        temp = temp->next;
    }
    if(temp == NULL) return 0;
    while(t != temp){
        count--;
        t = t->next;
    }
    return count;
}
//TC = O(N log N) using map
//TC = O(N) using unordered_map
//SC = O(N)
int length_Of_Loop(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    int timer = 1;
    while(temp){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return timer - value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}
//tortoise and hare
//TC = O(N) SC = O(1)
int legth_of_the_loop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            int cnt = 1;
            fast = fast->next;
            while(fast!=slow){
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
}
int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    cout<<legth_of_the_loop(head);
    return 0;
}