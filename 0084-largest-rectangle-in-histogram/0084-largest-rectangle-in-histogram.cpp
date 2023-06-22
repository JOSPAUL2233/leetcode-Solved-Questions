class Solution {
public:
    
    vector<int> nextSmallerElement(vector<int> heights){
        
        stack<int> st;
        vector<int> nextSmaller(heights.size(),0);
        
        for(int i = heights.size()-1 ; i >= 0 ; i--){
            
            //remove all the greater elements to the right from stack
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            //update the answer
            if(st.empty()){
                nextSmaller[i] = -1;
            }else{
                nextSmaller[i] = st.top();
            }
                        
            //push the current value into stack
            st.push(i);
            
        }
        
        return nextSmaller;
        
    }
    
    vector<int> prevSmallerElement(vector<int> heights){
        
        stack<int> st;
        vector<int> prevSmaller(heights.size(),0);
        
        for(int i = 0 ; i < heights.size() ; i++){
            
            //remove all the greater elements to the left from stack
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            //update the answer
            if(st.empty()){
                prevSmaller[i] = -1;
            }else{
                prevSmaller[i] = st.top();
            }
            
            //push the current value into stack
            st.push(i);
            
        }
        
        return prevSmaller;
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        
        //make next smaller and prev smaller arrays
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = prevSmallerElement(heights);
        
        int maxArea = 0;
        
        for(int i = 0; i < heights.size(); i++){
            
            //get the length of the rectangle
            int length = heights[i];
            
            //get the bridth of the rectangle
            if(next[i] == -1)
                next[i] = heights.size();
            
            int breadth = next[i] - prev[i] - 1;
            
            //calculate current area
            int area = length*breadth;
            
            //store the maximum area
            maxArea = area > maxArea ? area : maxArea;
            
        }
        
        return maxArea;
        
    }
};