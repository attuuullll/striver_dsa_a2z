#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int x, Node* y, Node* z){
		data = x;
		next = y;
		prev = z;
	}

	Node(int x){
		data = x;
		next = nullptr;
		prev = nullptr;
	}
};

Node* convertArr2DLL(vector<int> a){
	Node* head = new Node(a[0]);
	Node* mover = head;

	for(int i = 1; i < a.size(); i++){
		Node* t = new Node(a[i]);
		t->prev = mover;
		mover->next = t;
		mover = t;
	}

	return head;
}

void print(Node* head){
	Node* temp = head;

	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
}
// TC = O(N)    SC = O(1)
Node* removeDuplicate(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    while(temp->next){
        if(temp->next->data == temp->data ){
            Node* t = temp->next;
            temp->next = temp->next->next;
            if(temp->next) temp->next->prev = temp;
            delete t;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
int main(){
    vector<int> a = {1, 1, 2, 3, 4, 4, 5, 5, 5, 6, 7, 7};
    Node* head = convertArr2DLL(a);
    head = removeDuplicate(head);
    print(head);
    return 0;
}