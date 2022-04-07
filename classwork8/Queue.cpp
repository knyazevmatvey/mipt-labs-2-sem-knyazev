#include <iostream>
using namespace std;

struct Node {
	int field;
	Node* prev;
	Node* next;
};

void Tie(Node* first, Node* second) {
	// creates bonds between first and second nodes
	if (first != nullptr) first->next = second;
	if (second != nullptr) second->prev = first;
}

struct Queue {
	Node* head;
	Node* tail;

	Queue(int value) {
		Node* temp = new Node;
		temp->field = value;
		Tie(nullptr, temp);
		Tie(temp, nullptr);
		head = temp;
		tail = temp;
	}

	void enqueue(int value) {
		Node* temp = new Node;
		temp->field = value;
		Tie(tail, temp);
		Tie(temp, nullptr);
		if (tail == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail = temp;
		}
	}

	void dequeue() {
		if (head != nullptr) {
			if (head->next == nullptr) {
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else {
				Node* new_head = head->next;
				Tie(nullptr, new_head);
				delete head;
				head = new_head;
			}
		}
	}

	bool is_empty() {
		if (head == nullptr) return true;
		if (head != nullptr) return false;
	}

	int size() {
		Node* current = head;
		int ans = 0;
		while (current != nullptr) {
			current = current->next;
			ans++;
		}
		return ans;
	}

	void print() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->field;
			current = current->next;
			if (current != nullptr) cout << ' ';
		}
		cout << endl;
	}
};

int main() {
	bool want_to_test = true;
	if (want_to_test) {
		Queue q(1);
		q.print();

		q.enqueue(2);
		q.print();

		q.enqueue(3);
		q.enqueue(4);
		q.enqueue(5);
		q.print();

		int times = 6;
		for (int i = 0; i < times; i++) {
			cout << "i = " << i << ": ";
			q.dequeue();
			q.print();
		}

		if (q.is_empty()) cout << "empty queue" << endl;

		q.enqueue(6);
		q.enqueue(7);
		q.enqueue(8);
		q.print();
		if (!q.is_empty()) cout << "non-empty queue" << endl;

		cout << "size = " << q.size() << endl;
	}
}






