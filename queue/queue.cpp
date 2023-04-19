#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Queue {
	Node* head;
	Node* tail;
};

Node* makeNode(int x) {
	Node* tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

int Size(Node* node) {
	int dem = 0;
	while (node != NULL) {
		dem++;
	}
	return dem;
}

bool Empty(Queue qu) {
	if (qu.head == NULL)
		return true;
	return false;
}
bool Full(Queue qu,int lim) {
	if (Size(qu.head) == lim)
		return true;
	return 0;
}

void addLast(Queue& hd, int x) {
	Node* tmp = makeNode(x);
	if (hd.head == NULL) {
		hd.head = hd.tail = tmp;
	}
	else {
		Node* last = hd.head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = tmp;
		hd.tail = last->next;
	}
}


void enQueue(Queue& qu, int x) {
	addLast(qu, x);
}
void deleteLast(Queue& qu) {
	Node* tmp = qu.head;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = NULL;
	qu.tail = tmp;
}
void deQueue(Queue& qu) {
	deleteLast(qu);
}
int Peek(Queue& qu) {
	return qu.tail->data;
}

int main() {
	Queue qu;
	qu.head = qu.tail = NULL;
	int lim;
	cout << "Phan tu cua hang doi: "; cin >> lim;
	int n;
	cout << "So luong phan tu muon su dung: "; cin >> n;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		enQueue(qu, x);
	}
	
	cout << endl << qu.head->data << "     " << qu.tail->data << endl;
	deQueue(qu);
	cout << endl << qu.head->data << "     " << qu.tail->data << endl;
	cout << "\nPhan tu duoc doc la: " << Peek(qu) << endl;
	system("pause");
	return 0;
}

