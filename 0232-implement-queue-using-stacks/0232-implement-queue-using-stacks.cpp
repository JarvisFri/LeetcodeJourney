class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> s1, s2;
    void push(int x) {
        // while(!s1.empty()){
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        s1.push(x);
        // while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }

    }
    
    int pop() {
        //Move everything to s2
        peek();
        int temp=s2.top();
        s2.pop();
        return temp;
    }
    
    int peek() {
        //Move all elt s2 if s2 is empty return s2.top
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty()&& s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */