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
// tc: O(len)+O(len-N) sc: O(1) 
Node* removeNthFromEnd(Node* head,int n){
	int cnt=0;
	Node* temp=head;
	while(temp){
		cnt++;
		temp=temp->next;
	}
	if(cnt==n){
		Node* delNode=head;
		head=head->next;
		delete delNode;
		return head;
	}
	int res=cnt-n;
	temp=head;
	while(res>1){
		temp=temp->next;
		res--;
	}
	Node* delNode=temp->next;
	temp->next=temp->next->next;
	delete delNode;
	return head;
}
//tc:O(len) sc:O(1)
Node* remove_Nth_from_end(Node* head, int n){
    Node* fast = head;
    for(int i=0; i<n; i++){
        fast = fast->next;
    }
    if(fast==NULL){
		Node* delNode=head;
		head=head->next;
		delete delNode;
		return head;
	}
    Node* slow = head;
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}
int main(){
    vector<int> a = {2, 4, 6, 8, 9, 10};
    int n = 2;
    Node* head = convertArr2LL(a);
    head = removeNthFromEnd(head,2);
    print(head);
}