#include<stack>
#include<unordered_map>

using namespace std;

bool balancedBrackets(string str) {
  string openingBracket = "([{";
	string closingBracket = ")]}";
	unordered_map<char, char> matchingBrackets{
		{')', '('}, {']', '['}, {'}', '{'}};
	
	stack<char> stack;
	for(auto ch: str) {
		if(openingBracket.find(ch) != string::npos) {
			stack.push(ch);
		} else if(closingBracket.find(ch) != string::npos) {
			if(stack.empty()) {
				return false;
			}
			if(stack.top() == matchingBrackets[ch]) {
				stack.pop();
			} else {
				return false;
			}
		}
	}
  return stack.empty();
}

// #include <stack>

// using namespace std;

// bool balancedBrackets(string str) {
// 	stack<char> stack;
//   for(auto ch: str) {
// 		if(ch != ')' && ch != ']' && ch != '}' && ch != '(' && ch != '[' && ch != '{') {
// 			continue;
// 		} else if(stack.empty()) {
// 			if(ch == ')' || ch == ']' || ch == '}') {
// 				return false;
// 			} else {
// 				stack.push(ch);
// 			}
// 		} else {
// 			if(ch == ')') {
// 				if(stack.top() != '(') {
// 					return false;	
// 				} else {
// 					stack.pop();
// 				}
// 			} else if(ch == ']') {
// 				if(stack.top() != '[') {
// 					return false;	
// 				} else {
// 					stack.pop();
// 				}
// 			} else if(ch == '}') {
// 				if(stack.top() != '{') {
// 					return false;	
// 				} else {
// 					stack.pop();
// 				}
// 			} else {
// 				stack.push(ch);
// 			}
// 		}
// 	}
//   return stack.empty();
// }
