class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        // while(!st1.empty())
        //     st1.pop();
        // while(!st2.empty())
        //     st2.pop();
    }
    
    void push(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int ans=st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        if(st1.empty())
            return true;
        return false;
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