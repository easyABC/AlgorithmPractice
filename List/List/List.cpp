// List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct student
{
	int data;
	struct student * next;
}node;

void print(node *head)
{
	if (head == nullptr)
		return;
	node *p = head;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

node* create(void)
{
	int data;
	node * head = nullptr;
	node * p = head;
	while (cin >> data) {
		node * s = new node;
		s->data = data;
		if (head == nullptr) {
			head = s;
			s->next = nullptr;
			p = head;
		}
		else {
			p->next = s;
			p = p->next;
			s->next = nullptr;
		}
	}
	return head;
}

node *insert(node * head, int data)
{
	node * s = new node;
	node *p1, *p2 = nullptr;
	s->data = data;

	p1 = head;
	while (p1 != nullptr && p1->data < data) {
		p2 = p1;
		p1 = p1->next;
	}

	if (p1 == head) {
		head = s;
		s->next = p1;
	}
	else {
		p2->next = s;
		s->next = p1;
	}

	return head;
}

node *del(node *head, int data)
{
	node *p1, *p2 = nullptr;
	p1 = head;
	
	while (p1 != nullptr) {
		while (p1 != nullptr && p1->data != data) {
			p2 = p1;
			p1 = p1->next;
		}

		if (p1 != nullptr) {
			if (p1 == head) {
				head = p1->next;
				delete p1;
				p1 = head;
			}
			else {
				p2->next = p1->next;
				delete p1;
				p1 = p2->next;
			}	
		}
	}

	return head;
}

int list_len(node *head)
{
	node *p = head;
	int len = 0;
	while (p != nullptr) {
		len++;
		p = p->next;
	}
	return len;
}

node *sort(node *head)
{
	int temp, len;
	node *p1;
	len = list_len(head);

	for (int i = 1; i < len; ++i) {
		p1 = head;
		for (int j = 0; j < len - i; ++j) {
			if (p1->data > p1->next->data) {
				temp = p1->data;
				p1->data = p1->next->data;
				p1->next->data = temp;
			}
			p1 = p1->next;
		}
	}
	return head;
}

int main()
{
	node *head = nullptr;

	head = create();
	print(head);

	head = insert(head, 3);
	print(head);

	head = insert(head, 10);
	print(head);

	head = del(head, 3);
	print(head);

	head = del(head, 10);
	print(head);

	head = sort(head);
	print(head);

	system("PAUSE");
    return 0;
}

