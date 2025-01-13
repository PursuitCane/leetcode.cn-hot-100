class MinStack {
public:
    MinStack() {
        size = 0;
        
    }
    
    void push(int val) {
        st.push(val);
        size++;
        if (mon.empty()) {
            mon.push(make_pair(val, size));
            return;
        }
        if (mon.top().first  >= val) {
            mon.push(make_pair(val, size));
        }
        
    }
    
    void pop() {
        st.pop();
        if (mon.top().second == size) {
            mon.pop();
        }
        size--;
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return mon.top().first;
        
    }

    stack<int> st;
    stack<pair<int, int>> mon;
    int size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
