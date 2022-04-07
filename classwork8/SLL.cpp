#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
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

void node_add(Node** head_ptr, int value, int index) {
	Node* current = *head_ptr;
	Node* prev = nullptr;
	int i = 0;
	while (current != nullptr) {
		if (i == index) break;
		prev = current;
		current = current->next;
		i++;
	}

	Node* temp = new Node;
	temp->field = value;

	if ((current != nullptr) || ((current == nullptr) && (i == index))) {
		temp->next = current;
		if (i != 0) prev->next = temp;
		if (i == 0) *head_ptr = temp;
	}	
}

void node_pop(Node** head_ptr) {
	Node* prev = nullptr;
	Node* current = *head_ptr;
	if (current != nullptr) {
		while (current->next != nullptr) {
			prev = current;
			current = current->next;
		}
		if (prev != nullptr) {
			prev->next = nullptr;
		}
		else {
			*head_ptr = nullptr;
		}
		// �� ���� ���� ������� current->field, �� ���������� �������� �� ���������
		// delete current->field;
		delete current;
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

void node_delete_list(Node** head_ptr) {
	Node* current = *head_ptr;
	while (current->next != nullptr) {
		Node* prev = current;
		current = current->next;
		delete prev;
	}
	delete current;
	*head_ptr = nullptr;
}

Node* node_find_by_value(Node* head, int value) {
	Node* current = head;
	while (current->field != value) { 
		current = current->next; 
		if (current == nullptr) break;
	}
	return current;
}

Node* node_find_by_index(Node* head, int index) {
	Node* current = head;
	int i = 0;
	while (i != index) {
		current = current->next;
		i++;
		if (current == nullptr) break;
	}
	return current;
}

Node* node_delete_by_value(Node** head_ptr, int value) {
	Node* prev = nullptr;
	Node* current = *head_ptr;
	while (current->field != value) {
		prev = current;
		current = current->next;
		if (current == nullptr) break;
	}

	if (current != nullptr) {
		if (prev == nullptr) {
			*head_ptr = current->next;
		}
		else {
			prev->next = current->next;
		}
	}

	return current;
}

Node* node_delete_by_index(Node** head_ptr, int index) {
	Node* prev = nullptr;
	Node* current = *head_ptr;
	int i = 0;
	while (i != index) {
		prev = current;
		current = current->next;
		i++;
		if (current == nullptr) break;
	}

	if (current != nullptr) {
		if (prev == nullptr) {
			*head_ptr = current->next;
		}
		else {
			prev->next = current->next;
		}
	}

	return current;
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

	void add(int value, int index) {
		node_add(&head, value, index);
	}

	void pop() {
		node_pop(&head);
	}

	void print_list() {
		node_print_list(head);
	}

	void delete_list() {
		node_delete_list(&head);
	}

	Node* find_by_value(int value) {
		return node_find_by_value(head, value);
	}

	Node* find_by_index(int index) {
		return node_find_by_index(head, index);
	}

	Node* delete_by_value(int value) {
		return node_delete_by_value(&head, value);
	}

	Node* delete_by_index(int index) {
		return node_delete_by_index(&head, index);
	}
};

int main() {
	bool want_to_test = true;
	if (want_to_test) {
		// testing
		List a(1);
		a.print_list();
		a.append(3);
		a.print_list();
		a.pop();
		a.print_list();
		a.pop();
		a.print_list();

		a.append(0);
		a.append(1);
		a.append(2);
		a.append(3);
		a.print_list();

		a.add(10, 0);
		a.print_list();
		a.delete_by_index(0);
		a.print_list();

		a.add(10, 1);
		a.print_list();
		a.add(10, 4);
		a.print_list();
		a.add(10, 6);
		a.print_list();
		a.add(10, 8);
		a.print_list();

		a.delete_by_value(10);
		a.print_list();
		a.delete_by_value(5);
		a.print_list();

		a.delete_by_index(9);
		a.print_list();
		a.delete_by_index(5);
		a.print_list();
		a.delete_by_index(1);
		a.print_list();

		// checking that delete function returns the right node
		Node* check = a.delete_by_index(1);
		cout << "deleted node with field " << check->field << endl;
		a.print_list();

		check = a.delete_by_value(10);
		cout << "deleted node with field " << check->field << endl;
		a.print_list();

		check = a.delete_by_value(5);
		cout << "tried to delete none-existing node: node_ptr = " << check << endl;
		a.print_list();


		cout << "end.";

		_CrtDumpMemoryLeaks();
	}
}