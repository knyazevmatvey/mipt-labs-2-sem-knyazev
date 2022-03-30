#include <iostream>
using namespace std;

struct Node {
	int field;
	Node* next;
};

struct Stack {
	Node* top;

	Stack(int field) {
		Node* temp = new Node;
		temp->field = field;
		temp->next = nullptr;
		top = temp;
	};
};

void push(Stack& st, int value) {
	Node* top = st.top;
	Node* temp = new Node;
	temp->field = value;
	temp->next = top;
	st.top = temp;
}

void print_stack(Stack st) {
	// prints elements of stack st starting from top
	Node* current = st.top;
	while (current != nullptr) {
		cout << current->field;
		current = current->next;
		if (current != nullptr) cout << " ";
	}
	cout << endl;
}

Node* pop(Stack& st) {
	Node* temp = st.top;
	st.top = temp->next;
	return temp;
}

// renamed cause there was some name conflict with std::is_empty and 
// I don't want to get rid of using namespace std;
bool stack_is_empty(Stack& st) {
	return (st.top == nullptr);
}

Node* Top(Stack& st) {
	return st.top;
}




int main() {
	bool want_to_test = false;
	if (want_to_test) {
		Stack st = Stack(5);
		print_stack(st);
		push(st, 7);
		push(st, 9);
		print_stack(st);
		Node* useless = pop(st);
		print_stack(st);
		cout << "node that we got from popping has field " << useless->field << endl;

		Node* top_node = Top(st);
		cout << "node that we got from top has field " << top_node->field << endl;
		print_stack(st);

		cout << stack_is_empty(st) << endl;
		pop(st);
		print_stack(st);
		cout << stack_is_empty(st) << endl;
		pop(st);
		print_stack(st);
		cout << stack_is_empty(st) << endl;
	}
}