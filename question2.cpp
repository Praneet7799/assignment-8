#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		Node() {
			data = 0;
			next = NULL;
		}
};

class Stack {
	private:
		Node* head;
		Node* tail;
		int n;

	public:
		Stack() {
			head = NULL;
			tail = NULL;
			n = 0;
		}

		void push(int x);
		void pop();
		void display();
};

void Stack::push(int x) {
	Node* ptemp = new Node;
	ptemp->data = x;
	ptemp->next = NULL;

	if (head == NULL) {
		head = ptemp;
		tail = ptemp;
		++n;
	} else {
		tail->next = ptemp;
		tail = ptemp;
		++n;
	}
}

void Stack::pop() {
	Node* move = head;
	for (int j=0; j<n-2; ++j)
		move=move->next;

	move->next = NULL;
	tail = move;
	--n;
}

void Stack::display() {
	if (head == NULL) {
		cout << "There are no elements in the stack." << endl;
	} else {
		Node* move = head;
		while(move != NULL) {
			cout << move->data << endl;
			move = move->next;
		}
	}
}






int length(int* array) {
	int i;
	for (i=0; *(array+i)!='\0'; ++i) {}

	return i;
}

void initialize(int* array, int size) {
	for (int i=0; i<size; ++i) {
		*(array+i) = '\0';
	}
}

void push(int* array, int x) {
	*(array+length(array)) = x;
}

void pop(int* array) {
	*(array+length(array)-1) = '\0';
}

void display(int* array) {
	for (int i=0; i<length(array); ++i) {
		cout << *(array+i) << endl;
	}
}

int main() {
	/*Implementation as an array*/
  int var[50];
	initialize(var, 50);

	cout << length(var) << endl;
	cout << "Enter five values of stack: " << endl;
	int fi=0;
	for (int i=0; i<5; ++i) {
		cin >> fi;
		push(var, fi);
	}
	pop(var);
	display(var);
  
  /*Implementation as a Linked list*/
  Stack stack1;
	int var=0;
	cout << "Enter five elements to the list: " << endl;
	for (int i=0; i<5; ++i) {
		cin >> var;
		stack1.push(var);
	}

	stack1.display();
	stack1.push(25);
	stack1.display();
	stack1.pop();
	stack1.display();


	return 0;
}
