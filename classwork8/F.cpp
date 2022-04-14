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

	int get_top() {
		if (top != nullptr) return (top->field);
		else return -100;
	}
};


int main() {
	Stack st;
	while (true) {
		char temp = cin.get();
		if (temp == '\n') break;

		int num = temp - '0';
		if ((0 <= num) && (num <= 9)) st.push(num);

		if ((temp == '+') || (temp == '-') || (temp == '*') || (temp == '/')) {
			int b = st.pop();
			int a = st.pop();

			if (temp == '+') st.push(a + b);
			if (temp == '-') st.push(a - b);
			if (temp == '*') st.push(a * b);
			if (temp == '/') st.push(a / b);
		}
	}
	cout << st.get_top();
}