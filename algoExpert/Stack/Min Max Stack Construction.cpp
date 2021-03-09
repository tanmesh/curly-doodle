#include <stack>

using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
	stack<pair<int, pair<int, int>>> stack;
public:
  int peek() {
    if(stack.empty()) {
			return -1;
		}
    return stack.top().first;
  }

  int pop() {
    if(stack.empty()) {
			return -1;
		}
		int top = this->peek();
		stack.pop();
		
    return top;
  }

  void push(int number) {
    if(stack.empty()) {
			stack.push({number, {number, number}});
		} else {
			pair<int, int> top = stack.top().second;
			int minVal = min(number, top.first);
			int maxVal = max(number, top.second);
			stack.push({number, {minVal, maxVal}});
		}
  }

  int getMin() {
    if(stack.empty()) {
			return -1;
		}
    return stack.top().second.first;
  }

  int getMax() {
    if(stack.empty()) {
			return -1;
		}
    return stack.top().second.second;
  }
};
