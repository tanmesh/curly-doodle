class Solution {
    vector<int> buildTree(string expression, int startId, int endId) {
        vector<int> result;
        
        for(int i = startId; i < endId; ++i) {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> leftPart = buildTree(expression, startId, i - 1);
                vector<int> rightPart = buildTree(expression, i + 1, endId);
                for(auto value1: leftPart) {
                    for(auto value2: rightPart) {
                        switch(expression[i]) {
                            case '+': result.push_back(value1 + value2); break;
                            case '-': result.push_back(value1 - value2); break;
                            case '*': result.push_back(value1 * value2); break;
                        }
                    }
                }
            }
        }
        
        if(result.size() == 0) {
            int operand = 0;
            int i = startId;
            while(i < expression.size() && isdigit(expression[i])) {
                operand = 10 * operand + (expression[i] - '0');
                ++i;
            }
            result.push_back(operand);
        }
        
        return result;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        if(expression.length() == 0) {
            return {};
        }
        return buildTree(expression, 0, expression.size() - 1);
    }
};