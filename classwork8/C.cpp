#include <iostream>
using namespace std;

struct Node {
	int field;
	Node* next;
};

// I had to rename node functions so that my compilator doesn't complain 
// about using them inside the list structure with the same name for list functions

void node_append(Node** head_ptr, int value) {
	if (*head_ptr == nullptr) {
		Node* current = new Node;
		current->field = value;
		current->next = nullptr;
		*head_ptr = current;
	}
	else {
		Node* current = *head_ptr;
		while (current->next != nullptr) current = current->next;
		Node* temp = new Node;
		temp->field = value;
		temp->next = nullptr;
		current->next = temp;
	}
}

void node_print_list(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		cout << current->field;
		current = current->next;
		if (current != nullptr) cout << " ";
	}
	cout << endl;
}

struct List {
	Node* head;

	List(int value) {
		head = new Node;
		head->field = value;
		head->next = nullptr;
	}

	void append(int value) {
		node_append(&head, value);
	}

	void print_list() {
		node_print_list(head);
	}
};

void reverse(List &a) {
	Node* first = nullptr;
	Node* second = a.head;
	Node* third = a.head->next;

	while (third != nullptr) {
		second->next = first;
		first = second;
		second = third;
		third = third->next;
	}
	
	second->next = first;
	a.head = second;
}

int main() {
	bool want_to_test = false;
	if (want_to_test) {
		List a(1);
		a.append(2);
		a.append(3);
		a.print_list();
		reverse(a);
		a.print_list();
	}
}