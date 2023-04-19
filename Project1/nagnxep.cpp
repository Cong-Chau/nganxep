#include<iostream>
#include<stack>
using namespace std;

/*
* empty  /
* push  /
* pop  /
* peek  /
* size
*/

/*
		|  top  |5
		|       |4
		|       |3
		|       |2
		|_______|1
*/
struct Node {
	int data;
	Node* next;
};
struct Stack {
	Node* info;// phan tu tren cung cua ngan xep
};

Node* makeNode(int x) {
	Node* tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void addFirst(Node*& node, int x) {
	Node* tmp = makeNode(x);
	if (node == NULL)
		node = tmp;
	else {
		tmp->next = node;
		node = tmp;
	}
}

bool Empty(Node* node) {
	if (node == NULL)
		return NULL;
}


void Push(Node*& node, int x) {
	addFirst(node, x);
}
void Pop(Node*& node) {
	node = node->next;
}
int Peek(Node* node) {
	return node->data;
}
int Size(Node* node) {
	int dem = 0;
	while (node != NULL) {
		dem++;
		node = node->next;
	}
	return dem;
}


int main() {
//	Node* node = NULL;
	Stack a;
	a.info = NULL;
	int lim;
	cout << "So luong: "; cin >> lim;
	int n;
	cout << "So luong o trong muon su dung: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		Push(a.info, x);
	}
	Node* tmp = a.info;
	while (tmp != NULL) {
		cout << tmp->data << "  ";
		tmp = tmp->next;
	}
	cout << endl;
	Pop(a.info);
	cout << "Danh sach con lai: \n";
	Node* tmp2 = a.info;
	while (tmp2 != NULL) {
		cout << tmp2->data << "  ";
		tmp2 = tmp2->next;
	}

	cout << "\nPhan tu tren cung: " << Peek(a.info);
	cout << "\nSo luong phan tu: " << Size(a.info) << endl;
	system("pause");
	return 0;
}