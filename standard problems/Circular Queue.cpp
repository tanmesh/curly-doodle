#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

class MyCircularQueue {
public:
	vector<int> element;
	int front;
	int back;
	int size;

	MyCircularQueue(int k) {
		element.resize(k);
		front = -1;
		back = -1;
		size = k;
	}

	bool enQueue(int value) {
		if (isFull()) {
			return false;
		}
		if (front == -1 && back == -1) {
			front = 0;
		}
		back = (back + 1) % size;
		element[back] = value;
		return true;
	}

	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		if (front == back) {
			front = -1;
			back = -1;
			return true;
		}
		front = (front + 1) % size;
		return true;
	}

	int Front() {
		if (isEmpty()) {
			return -1;
		}
		return element[front];
	}

	int Rear() {
		if (isEmpty()) {
			return -1;
		}
		return element[back];
	}

	bool isEmpty() {
		if (front == -1 && back == -1) {
			return true;
		}
		return false;
	}

	bool isFull() {
		if ((back + 1) % size == front) {
			return true;
		}
		return false;
	}
};

int main () {
	fast
	int k, value;
	k = 1;
	value = 2;
	MyCircularQueue* obj = new MyCircularQueue(k);
	bool param_1 = obj->enQueue(value);
	cout << param_1 << endl;
	bool param_2 = obj->deQueue();
	cout << param_2 << endl;
	int param_3 = obj->Front();
	cout << param_3 << endl;
	int param_4 = obj->Rear();
	cout << param_4 << endl;
	bool param_5 = obj->isEmpty();
	cout << param_5 << endl;
	bool param_6 = obj->isFull();
	cout << param_6 << endl;
	return 0;
}