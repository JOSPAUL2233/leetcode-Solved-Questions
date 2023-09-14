class StockSpanner {
public:
    
    int index;
    stack<pair<int,int>> st;//pair --> index,value
    
    StockSpanner() {
        
        index = 0;
        
    }

    int next(int price) {
        
        //remove all the elements that are smaller than the price from stack
        while(!st.empty() && st.top().second <= price)
            st.pop();
        
        
        //calculate the return answer
        int ans = 0;
        
        if(st.empty())
            ans = index - (-1);
        else
            ans = index - st.top().first;
        
        //push the current value
        st.push({index,price});
        
        //increment index for next iteration
        index++;
        
        return ans;
         
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */