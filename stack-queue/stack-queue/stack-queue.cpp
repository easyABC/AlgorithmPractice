// stack-queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class myQueue
{
public:
	void pop(void);
	void push(int);
	int top(void);

private:
	stack<int> stack1;
	stack<int> stack2;
};


void myQueue::push(int data)
{
	stack1.push(data);
	return;
}

void myQueue::pop(void)
{
	if (stack2.empty()) {
		if (!stack1.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		else {
			return;
		}
	}
	stack2.pop();
	return;
}

int myQueue::top()
{
	if (stack2.empty()) {
		if (!stack1.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		else {
			throw exception("queue is null.");
		}
	}
	return stack2.top();
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	myQueue q;
	for (auto data : v) {
		q.push(data);
	}
	int count = 6;

	try{
		while (count--) {
			cout << q.top() << endl;
			q.pop();
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	
	system("PAUSE");
	return 0;
}

