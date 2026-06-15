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
// TC = O(N)   SC = O(1)
Node* deleteOccurences(Node* head, int key){
	while(head && head->data == key){
		Node* t = head;
		head = head->next;
		if(head) head->prev = NULL;
		delete t;
	}

	Node* temp = head;

	while(temp){
		if(temp->data == key){
			Node* t = temp;
			Node* back = temp->prev;
			Node* front = temp->next;

			if(back) back->next = front;
			if(front) front->prev = back;

			temp = front;
			delete t;
		}
		else{
			temp = temp->next;
		}
	}

	return head;
}

int main(){
	vector<int> a = {10, 4, 6, 10, 10, 3, 10};
	Node* head = convertArr2DLL(a);
	head = deleteOccurences(head, 10);
	print(head);
	return 0;
}