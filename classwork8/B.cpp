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
		// По идее надо удалить current->field, но компилятор ругается на следующее
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

	List() {
		head = nullptr;
	}

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


int find_loop(List* list_ptr) {
	if (list_ptr->head == nullptr) {
		return -1;
	}
	else {
		// during one iteration we will check if there's a loop in the nodes between the head node and the current one
		// for that we will check if the current node is equal to any of the previous ones;
		bool finished = false;
		bool found_loop = false;
		Node* current = list_ptr->head;

		while (!finished) {
			Node* temp = list_ptr->head;
			while (current != nullptr) {
				if (temp == current->next) {
					found_loop = true;
					temp = temp->next;
				}
				if (temp == current) break;
				temp = temp->next;
			}
			current = current->next;
			if ((current == nullptr) || (found_loop)) finished = true;
		}

		if (found_loop) {
			int ans = 0;
			Node* temp = list_ptr->head;
			while (temp != current) {
				ans++;
				temp = temp->next;
			}
			return ans;
		}
		else {
			return -1;
		}
	}
}

int main() {
	bool want_to_test = false;
	if (want_to_test) {
		Node* zeroth = new Node;
		Node* first = new Node;
		Node* second = new Node;
		Node* third = new Node;

		zeroth->next = first;
		first->next = second;
		second->next = third;
		third->next = third;	// change right side to nullptr, zeroth, first, second or third

		List a;
		a.head = zeroth;
		cout << find_loop(&a);
	}
}