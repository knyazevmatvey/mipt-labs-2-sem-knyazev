#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;
char operations[N] = {'+', '-', '*', '/', 'n'};

// here operations will be nodes
struct Node {
	char oper;
	int number;
	Node* right;
	Node* left;
};


struct Heap {
	Node* top;
};

void print_expression(char* math_expression, int left, int right) {
	char* current = math_expression;
	current += left;
	for (int i = 0; i <= right - left; i++) {
		cout << *current;
		current++;
	}
}

char first_symbol(char* math_expression, int expr_size) {
	// returns the first symbol, not equal to ' '
	char* current = math_expression;
	while (*current == ' ') {
		current++;
		if (current == nullptr) break;
	}
	if (current != nullptr) return *current;
}

char last_symbol(char* math_expression, int expr_size) {
	char* current = math_expression;
	current += expr_size - 1;
	while (*current == ' ') {
		current--;
		if (current == nullptr) break;
	}
	if (current != nullptr) return *current;
	else return 'w';
}

void skip_to_bracket(char** ptr) {
	// moves the ptr to the end of the bracket clause
	char* current = *ptr;
	current++;
	int counter = 1;

	while (counter != 0) {
		//cout << *ptr;
		if (*current == '(') counter++;
		if (*current == ')') counter--;
		current++;
	}
	*ptr = current;

}

Node* Heapify(char* math_expression, int expr_size){
	// checking if the whole expression is in brackets
	if ((first_symbol(math_expression, expr_size) == '(') && (last_symbol(math_expression, expr_size) == ')')) {
		char* current = math_expression;
		while (*current != '(') current++;
		char* last = math_expression + expr_size - 1;
		while (*last != ')') last--;
		return Heapify(current + 1, last - current - 1);
	}

	// main case
	else {

		// looking for the last operation to be implemented
		int minimal = 10;
		int border = -1;
		char* end = math_expression + expr_size;
		char* current = math_expression;
		while (current != end) {
			//cout << *current;
			if (*current == '(') {
				skip_to_bracket(&current);
			}
			else {
				for (int j = 0; j < N; j++) {
					if (*current == operations[j]) {
						if (j < minimal) {
							minimal = j;
							border = current - math_expression;
						}
					}
				}
				current++;
			}
		}

		// base of induction (no operations to do)
		if (minimal == 10) {
			Node* temp = new Node;
			temp->oper = 'n'; // 'n' for number
			temp->number = atoi(math_expression);
			temp->right = nullptr;
			temp->left = nullptr;
			return temp;
		}
		else {
			Node* temp = new Node;
			temp->oper = operations[minimal];
			temp->left = Heapify(math_expression, border);
			temp->right = Heapify(math_expression + border + 1, expr_size - border - 1);
			return temp;
		}
	}
}

int calculate(Node* top) {
	if (top->oper == 'n') return top->number;
	if (top->oper == '+') return (calculate(top->left) + calculate(top->right));
	if (top->oper == '-') return (calculate(top->left) - calculate(top->right));
	if (top->oper == '/') return (calculate(top->left) / calculate(top->right));
	if (top->oper == '*') return (calculate(top->left) * calculate(top->right));
}

int main() {
	// i'm assuming that i work with less than 'big' symbols
	int big = 1000;

	//cout << "Write your expression to calculate: ";

	int i = 0;
	char* input = new char[big];
	while (true) {
		char temp = cin.get();
		if (temp == '\n') break;
		input[i] = temp;
		i++;
	}
	int size = i;


	cout << calculate(Heapify(input, size));
}