#include <iostream>
using namespace std;

struct Node {
	int field;
	Node* next;
	Node* prev;
};

void Tie(Node* first, Node* second) {
	// creates bonds between first and second nodes
	if (first != nullptr) first->next = second;
	if (second != nullptr) second->prev = first;
}

struct List {
	Node* head;
	Node* tail;

	List(int value) {
		head = new Node;
		head->field = value;
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
	}

	void append(int value) {
		Node* new_tail = new Node;
		new_tail->field = value;
		Tie(tail, new_tail);
		Tie(new_tail, nullptr);
		
		// if the list is empty, head and tail become new_tail;
		// if the list is not empty, only tail becomes new_tail;
		if (tail == nullptr) {
			head = new_tail;
			tail = new_tail;
		}
		else {
			tail = new_tail;
		}
	}

	void add(int value, int index) {
		Node* current = head;
		int i = 0;

		// changing current to the node after which we will insert a new node
		while (current != nullptr) {
			if (i == index) break;
			current = current->next;
			i++;
		}

		if ((current != nullptr) || ((current == nullptr) && (i == index))) {
			Node* temp = new Node;
			temp->field = value;

			if (current == nullptr) Tie(tail, temp);
			if (current != nullptr) Tie(current->prev, temp);
			Tie(temp, current);

			bool insert_at_end = ((current == nullptr) && (i == index));
			bool insert_at_beg = (i == 0);
			if (insert_at_end) tail = temp;
			if (insert_at_beg) head = temp;
		}
	}

	void pop() {
		if (tail != nullptr) {
			// if the list consists of only one element
			if (tail->prev == nullptr) {
				// I'm not sure if that's the right way
				Node* current = tail;
				delete current;
				head = nullptr;
				tail = nullptr;
			}
			else {
				Tie(tail->prev, nullptr);
				Node* current = tail;
				tail = (tail->prev);
				delete current;
			}
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

	Node* find_by_value(int value) {
		Node* current = head;
		while (current->field != value) {
			current = current->next;
			if (current == nullptr) break;
		}
		return current;
	}

	Node* find_by_index(int index) {
		Node* current = head;
		int i = 0;
		while (i != index) {
			current = current->next;
			i++;
			if (current == nullptr) break;
		}
		return current;
	}

	void delete_by_value(int value) {
		Node* current = head;
		while (current->field != value) {
			current = current->next;
			if (current == nullptr) break;
		}
		if (current != nullptr) {
			Tie(current->prev, current->next);
			if (current->prev == nullptr) head = current->next;
			if (current->next == nullptr) tail = current->prev;
			delete current;
		}
	}

	void delete_by_index(int index) {
		Node* current = head;
		int i = 0;
		while (i != index) {
			current = current->next;
			i++;
			if (current == nullptr) break;
		}
		if (current != nullptr) {
			Tie(current->prev, current->next);
			if (current->prev == nullptr) head = current->next;
			if (current->next == nullptr) tail = current->prev;
			delete current;
		}
	}
};

int main() {
	bool want_to_test = true;
	if (want_to_test) {
		cout << "created list with element 1: ";
		List a(1);
		a.print_list();

		cout << "appended 2: ";
		a.append(2);
		a.print_list();

		cout << "popped: ";
		a.pop();
		a.print_list();

		cout << "popped: ";
		a.pop();
		a.print_list();

		cout << "popped: ";
		a.pop();
		a.print_list();


		cout << "appended 3: ";
		a.append(3);
		a.print_list();

		cout << "popped: ";
		a.pop();
		a.print_list();

		cout << "[look at code]: ";
		a.add(1, 0);
		a.add(2, 0);
		a.add(3, 2);
		a.add(4, 1);
		a.print_list();

		cout << "deleted: ";
		a.delete_list();
		a.print_list();

		cout << "appended 1, 2, 3: ";
		a.append(1);
		a.append(2);
		a.append(3);
		a.print_list();

		cout << "looking for 3: found " << a.find_by_value(3)->field << " at " << a.find_by_value(3) << endl;
		cout << "looking for -1: found " << a.find_by_value(-1) << endl;


		for (int i = 0; i < 7; i++) {
			int k = i - 2;
			cout << "looking for index " << k << ": found " << a.find_by_index(k);
			if (a.find_by_index(k) != nullptr) cout << " containing " << a.find_by_index(k)->field;
			cout << endl;
		}

		cout << "deleted element by value 3: ";
		a.delete_by_value(3);
		a.print_list();

		cout << "deleted element by value 0: ";
		a.delete_by_value(0);
		a.print_list();

		cout << "deleted element by index 10: ";
		a.delete_by_index(10);
		a.print_list();

		cout << "deleted element by index 0: ";
		a.delete_by_index(0);
		a.print_list();
	}
}






