class MinStack {
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        int minVal = INT_MAX;
        if(!minStack.empty()) {
            minVal = minStack.top();
        }
        if(val <= minVal) {
            minStack.push(val);
        }
    }
    
    void pop() {
        int topVal = mainStack.top();
        mainStack.pop();
        if(!minStack.empty()) {
            if(topVal == minStack.top()){
                minStack.pop();
            }
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
