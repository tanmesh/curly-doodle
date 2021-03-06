#include <bits/stdc++.h>

using namespace std;

string reverseWordsInString(string str) {
  stack<string> stack;
	
	int n = str.length();
	int i = 0;
	while(i < n) {
		string subStr = "";
		while(i < n && str[i] != ' ') {
			subStr += str[i];
			++i;
		}
		stack.push(subStr);
		
		subStr = "";
		while(i < n && str[i] == ' ') {
			subStr += str[i];
			++i;
		}
		stack.push(subStr);
	}
	
	string result = "";
	while(!stack.empty()) {
		result = result + stack.top();
		stack.pop();
	}
	
  return result;
}
