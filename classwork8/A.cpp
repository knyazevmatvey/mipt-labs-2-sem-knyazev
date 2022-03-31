#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	char field[20];
	Node* next;
};

// I had to rename node functions so that my compilator doesn't complain 
// about using them inside the list structure with the same name for list functions

void node_append(Node** head_ptr, char value[20]) {
	if (*head_ptr == nullptr) {
		Node* current = new Node;
		strcpy_s(current->field, value);
		current->next = nullptr;
		*head_ptr = current;
	}
	else {
		Node* current = *head_ptr;
		while (current->next != nullptr) current = current->next;
		Node* temp = new Node;
		strcpy_s(temp->field, value);
		temp->next = nullptr;
		current->next = temp;
	}
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

	List(char value[20]) {
		head = new Node;
		strcpy_s(head->field, value);
		head->next = nullptr;
	}

	void append(char value[20]) {
		node_append(&head, value);
	}

	Node* delete_by_index(int index) {
		return node_delete_by_index(&head, index);
	}
};

Node* move(List a, Node* current) {
	if (current->next == nullptr) {
		return a.head;
	}
	else {
		return current->next;
	}
}

int get_index(List a, Node* given) {
	Node* current = a.head;
	int ans = 0;
	while (current != given) {
		current = current->next;
		ans++;
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n;
	
	// костыль, ибо без объ€влени€ первого аргумента оно что-то не хочет
	char first[20];
	strcpy_s(first, "nothing");
	List people(first);
	for (int i = 0; i < n; i++) {
		char temp[20];
		cin >> temp;
		people.append(temp);
	} 
	people.delete_by_index(0);

	cin >> m;

	bool not_finished = ((people.head)->next != nullptr);
	Node* current = people.head;
	while (not_finished) {
		for (int i = 0; i < m-1; i++) current = move(people, current);
		int to_be_deleted = get_index(people, current);
		current = move(people, current);
		people.delete_by_index(to_be_deleted);
		not_finished = ((people.head)->next != nullptr);
	}
	cout << (people.head)->field;
}