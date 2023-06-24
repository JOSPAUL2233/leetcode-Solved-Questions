class MinStack {
    
    stack<int> st;
    stack<int> min;
    
    int minEle;
    
public:
    MinStack() {
        
        minEle = INT_MAX;
        
    }
    
    void push(int val) {
        
        st.push(val);
        
        if(val < minEle){
            minEle = val;
        }
                
        min.push(minEle);
                    
    }
    
    void pop() {
    
        st.pop();
        min.pop();
        
        if(!min.empty())
            minEle = min.top();
        else
            minEle = INT_MAX;

    }
    
    int top() {
        
        return st.top();
        
    }
    
    int getMin() {
        
        return min.top();
        
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