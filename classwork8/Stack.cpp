#include <iostream>
using namespace std;

struct Node {
	int field;
	Node* next;
};

struct Stack {
	Node* top;

	Stack() {
		top = nullptr;
	}

	Stack(int field) {
		Node* temp = new Node;
		temp->field = field;
		temp->next = nullptr;
		top = temp;
	};

	void push(int value) {
		Node* temp = new Node;
		temp->field = value;
		temp->next = top;
		top = temp;
	}

	int pop() {
		// it should work while the stack isn't empty
		int ans = top->field;
		Node* new_top = top->next;
		delete top;
		top = new_top;
		return ans;
	}

	bool is_empty() {
		return (top == nullptr);
	}

	int Top() {
		if (top != nullptr) return (top->field);
		else return -1;
	}
};

