#include<iostream>
using namespace std;

struct node {
	int info;
	node* next;
	node* prev;
};
node* head = 0;

// All Insert Functions
void insert_at_begin(int x) {
	node* p;
	p = new node;
	p->info = x;
	p->next = 0;
	p->prev = 0;
	if (head == 0)
		head = p;
	else {
		p->next = head;
		head->prev = p;
		head = p;
	}
	return;
}

void insert_at_end(int x) {
	node* p = 0, * t;
	p = new node;
	p->info = x;
	p->next = 0;
	p->prev = 0;
	if (head == 0)
		head = p;
	else {
		t = head;
		while (t->next != 0)
			t = t->next;
		t->next = p;
		p->prev = t;
	}
	return;
}

void insert_at_pos(int pos, int x) {
	node* p = 0, * q = 0, * t;
	int count = 0;
	if (head == 0) {
		cout << "LL is empty !....." << endl;
		return;
	}
	if (pos == 1) {
		p = new node;
		p->info = x;
		p->next = 0;
		p->prev = 0;
		p->next = head;
		head->prev = p;
		head = p;
	}
	else {
		t = head;
		count = 1;
		while (count != pos && t != 0) {
			q = t;
			t = t->next;
			count++;
		}
		if (t != 0) {
			p = new node;
			p->info = x;
			p->next = 0;
			p->prev = 0;
			q->next = p;
			p->prev = q;
			p->next = t;
			t->prev = p;
		}
		else
			cout << "Invalid Position........? " << endl;
	}
	return;
}

// All Delete Functions
int delete_at_begin() {
	node* p;
	int x;
	if (head == 0) {
		cout << "LL is empty......! " << endl;
		return -1;
	}
	p = head;
	x = head->info;
	head = head->next;
	if (head != 0)
		head->prev = 0;
	delete p;
	return x;
}

int delete_at_end() {
	node* t, * p = 0;
	int x;
	if (head == 0) {
		cout << "LL is empty.......!" << endl;
		return -1;
	}
	if (head->next == 0) {
		t = head;
		x = head->info;
		head = 0;
	}
	else {
		t = head;
		while (t->next != 0) {
			p = t;
			t = t->next;
		}
		p->next = 0;
		x = t->info;
	}
	delete t;
	return x;
}

int delete_at_pos(int pos) {
	node* q = 0, * t;
	int x, count = 0;
	if (head == 0) {
		cout << "LL is empyt............! " << endl;
		return -1;
	}
	if (pos == 1) {
		x = head->info;
		t = head;
		head = head->next;
		if (head != 0)
			head->prev = 0;
		delete t;
		return x;
	}
	t = head;
	count = 1;
	while (count != pos && t != 0) {
		q = t;
		t = t->next;
		count++;
	}
	if (t != 0) {
		x = t->info;
		q->next = t->next;
		if (t->next != 0)
			t->next->prev = q;
		delete t;
		return x;
	}
	else {
		cout << "Invalid Position..........? " << endl;
		return -1;
	}
}

int count() {
	node* t;
	int count = 0;
	t = head;
	while (t != 0) {
		t = t->next;
		count++;
	}
	return count;
}

int search(int x) {
	node* t;
	int found = 0;
	t = head;
	while (t != 0) {
		if (t->info == x) {
			found = 1;
			break;
		}
		else
			t = t->next;
	}
	return found;
}

void display() {
	node* t;
	t = head;
	if (head == 0) {
		cout << "LL is empty .......! " << endl;
		return;
	}
	cout << "All Elem in LL is : " << endl;
	while (t != 0) {
		cout << t->info << endl;
		t = t->next;
	}
	return;
}

int main() {
	int ch, v, p1, p2, x;
	do {
		cout << " 1.Insert_at_begin 2.Insert_at_end 3.Insert_at_pos " << endl;
		cout << " 4.Delete_at_begin 5.Delete_at_end 6.Delete_at_pos" << endl;
		cout << " 7.Count\n 8.Search\n 9.Display\n 10.Exit\n" << endl;
		cout << " Enter the choice :  ";  cin >> ch;
		switch (ch) {
		case 1: cout << "Enter values to insert_at_begin : " << endl;
			cin >> v;     insert_at_begin(v);      break;
		case 2:cout << "Enter values to Insert_at_end : " << endl;
			cin >> v;      insert_at_end(v);    break;
		case 3:cout << "Enter Pos to insert_at_poition : ";
			cin >> p1;    cout << "Enter value : " << endl;
			cin >> v;     insert_at_pos(p1, v);     break;
		case 4: x = delete_at_begin();
			cout << " Value is Deleted  : " << x << endl;    break;
		case 5: x = delete_at_end();
			cout << " Value is Deleted  : " << x << endl;    break;
		case 6:cout << "Enter Pos to delete_at_position : ";
			cin >> p2;     x = delete_at_pos(p2);
			cout << " Value is Deleted  : " << x << endl;    break;
		case 7:v = count();
			cout << "Total Elem in LL : " << v << endl;    break;
		case 8:cout << "Enter value to search in LL : " << endl;
			cin >> v;     x = search(v);
			if (x == 1)
				cout << "Element is  found  : " << v << endl;
			else
				cout << "Element not found ........! " << endl;
			break;
		case 9:display();     break;
		default:cout << "Exiting..." << endl;
			ch = 10;
		}
	} 
	while (ch != 10); 
	return 0;
}
