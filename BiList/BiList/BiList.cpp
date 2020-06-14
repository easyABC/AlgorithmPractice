// BiList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node * pPre;
	struct Node * pNext;
}BiListNode;


BiListNode* BiListCreat(BiListNode * head)
{
	int data;
	BiListNode * pNew, *p1;
	while (cin >> data) {
		pNew = new BiListNode;
		pNew->data = data;
		p1 = head;
		if (head == nullptr) {
			head = pNew;
			pNew->pNext = nullptr;
			pNew->pPre = nullptr;
		}
		else{
			while (p1->pNext != nullptr)
				p1 = p1->pNext;
			p1->pNext = pNew;
			pNew->pPre = p1;
			pNew->pNext = nullptr;
		}
	}
	return head;
}

void print(BiListNode * head)
{
	BiListNode * p;
	if (head == nullptr) {
		return;
	}
	p = head;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BiListNode * head = nullptr;
	head = BiListCreat(head);
	print(head);
	system("PAUSE");
	return 0;
}

