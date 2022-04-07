#include <iostream>
using namespace std;

struct Node {
	int field;
	Node* next;
	Node* prev;
	int index;
};

void Tie(Node* first, Node* second) {
	// creates bonds between first and second nodes
	if (first != nullptr) first->next = second;
	if (second != nullptr) second->prev = first;
}

struct List {
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* mid = nullptr;
	int length = 0;


	List() {
		head = nullptr;
		tail = nullptr;
		mid = nullptr;
		length = 0;
	}

	void append(int value) {
		Node* new_tail = new Node;
		new_tail->field = value;
		Tie(tail, new_tail);
		Tie(new_tail, nullptr);

		// if the list is empty, head and tail become new_tail;
		// if the list is not empty, only tail becomes new_tail;
		if (tail == nullptr) {
			new_tail->index = 0;
			head = new_tail;
			tail = new_tail;
		}
		else {
			new_tail->index = tail->index + 1;
			tail = new_tail;
		}

		length++;
		if (length == 1) {
			mid = head;
		}
		else if (length % 2 == 1) {
			mid = mid->next;
		}
	}

	void print_list() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->field;
			current = current->next;
			if (current != nullptr) cout << ' ';
		}
		cout << endl;
	}

	void delete_list() {
		Node* current = head;
		while (current != nullptr) {
			Node* prev = current;
			current = current->next;
			delete prev;
		}
		delete current;
		head = nullptr;
		tail = nullptr;
	}
};

int main() {
	List a;
	int n;
	cin >> n;


	
	for (int i = 0; i < n; i++) {
		char temp;
		cin.get(temp);
		a.append(temp-'0');
	}
	

	// going to mid and checking if there's one or zero and then going to the border
	// so the worst case is n/2 < n;
	// i assume that there's always at least one 1 and at least one 0
	if (a.mid->field == 1) {
		Node* current = a.mid;
		while (current->field == 1) current = current->prev;
		cout << current->index + 1;
	}
	if (a.mid->field == 0) {
		Node* current = a.mid;
		while (current->field == 0) current = current->next;
		cout << current->index + 0;
	}
}






