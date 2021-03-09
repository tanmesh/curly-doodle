class MinStack {
    stack<pair<int, int>> stack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(!stack.empty()) {
            int minSoFar = stack.top().second;
            minSoFar = min(minSoFar, x);
            stack.push({x, minSoFar});
        } else {
            stack.push({x, x});
        }
    }
    
    void pop() {
        if(!stack.empty()) {
            stack.pop();
        }
    }
    
    int top() {
        pair<int, int> top = {};
        if(!stack.empty()) {
            top = stack.top();
        }
        return top.first;
    }
    
    int getMin() {
        pair<int, int> top = {};
        if(!stack.empty()) {
            top = stack.top();
        }
        return top.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */