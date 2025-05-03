class MinStack {
public:
    MinStack() {
        
    }
    
    stack<int> regStk,minStk;

    void push(int val) {
        regStk.push(val);
        if(minStk.empty()) minStk.push(val);
        else minStk.push(min(minStk.top(),val));
    }
    
    void pop() {
        minStk.pop();
        regStk.pop();
    }
    
    int top() {
        return regStk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */