class MyStack {
    
    queue<int> que;
    
public:
    MyStack() {
        
        
    }
    
    void push(int x) {
        
        //push the element into que
        que.push(x);

        //put all the elements from que to que itself but size - 1 times so as to keep the last
        //inserted index to be in the front side

        int iterCount = que.size() - 1;

        while(iterCount--){

            que.push(que.front());

            que.pop();

        }
        
    }
    
    int pop() {
        
        int temp = que.front();
        
        que.pop();
        
        return temp;
        
    }
    
    int top() {
        
        return que.front();
        
    }
    
    bool empty() {
        
        if(que.empty())
            return true;
        else
            return false;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */