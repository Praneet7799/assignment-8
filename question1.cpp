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

class LinkedList {
	private:
		Node* head;
		Node* tail;
		int n;

	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			n = 0;
		}

		void addNode(int x);
		void insertNode(int x, int i);
		void deleteNode(int i);
		void display();
};

void LinkedList::addNode(int x) {
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
		++n;
	} else {
		tail->next = temp;
		tail = temp;
		++n;
	}
}

void LinkedList::insertNode(int x, int i) 
{if (i > n) 
  {cout << "There aren't enough elements in the list \n";
	}
  else if (i == 0) 
  {Node* temp = new Node;
		temp->data = x;
		temp->next = head;
		head = temp;
		++n;
	} 
  else if (i == n) 
  {Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (head == NULL) 
  {head = temp;
		tail = temp;
		++n;
	} 
  else 
  { tail->next = temp;
		tail = temp;
		++n;
	} 
  }
  else 
  {
		Node* temp = new Node;
		temp->data = x;

		Node* locate = head;

		for (int j=0; j<i-1; ++j) {
			locate = locate->next;
		}

		temp->next = locate->next;
		locate->next = temp;
		++n;
	}
}

void LinkedList::deleteNode(int i) {
	if (i >= n) {
		cout << "There aren't enough elements in the list \n";
	} else if (i == 0) {
		head = head->next;
		--n;
	} else if (i == n-1) {
		Node* locate = head;
		for (int j=0; j<i-1; ++j) {
			locate = locate->next;
		}

		tail = locate;
		locate->next = NULL;
		--n;
	} else {
		Node* locate = head;
		for (int j=0; j<i-1; ++j) {
			locate = locate->next;
		}

		locate->next = (locate->next)->next;
		--n;
	}
}

void LinkedList::display() {
	if (head == NULL) {
		cout << "The list is empty." << endl;
	} else {
		Node* temp = new Node;
		temp = head;
		
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}

int main() {
	LinkedList list1;
	int var;
	cout << "Enter five elements to the list: " << endl;
	for (int i=0; i<5; ++i) {
		cin >> var;
		list1.addNode(var);
	}
	list1.display();
  cout<<"\n Enter the position and the element to add \n";
  int pos;
  cin>>pos>>var;
  list1.insertNode(var,pos);
  cout<<"\n enter the position of the element to delete ";
  cin>>pos;
	list1.deleteNode(pos);

	cout << endl;
	list1.display();
	

	return 0;
}
