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
//tc = O(N2)  sc = O(1)
vector<vector<int>> findSum(Node* head, int sum){
	vector<vector<int>> ds;
	Node* temp1 = head;
	while(temp1 != NULL){
		Node* temp2 = temp1->next;
		while(temp2 != NULL && temp1->data + temp2->data <= sum){
			if(temp1->data + temp2->data == sum){
				ds.push_back({temp1->data, temp2->data});
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return ds;
}
//tc = O(N)  sc = O(1)
vector<vector<int>> findSum(Node* head,int sum){
	vector<vector<int>> ans;
	if(head==NULL) return ans;
	Node* left=head;
	Node* right=head;
	while(right->next) right=right->next;
	while(left!=right && right->next!=left){
		int curr=left->data+right->data;
		if(curr==sum){
			ans.push_back({left->data,right->data});
			left=left->next;
			right=right->prev;
		}
		else if(curr<sum){
			left=left->next;
		}
		else{
			right=right->prev;
		}
	}
	return ans;
}
int main(){
	vector<int> a = {1, 2, 3, 4, 9};
	Node* head = convertArr2DLL(a);
		vector<vector<int>> ans = findSum(head, 5);
	for(auto &it : ans){
		cout << "("<<it[0] << "," << it[1] <<")"<<endl;
	}
	return 0;
}