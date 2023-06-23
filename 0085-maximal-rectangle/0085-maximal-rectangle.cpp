class Solution {
public:
    
    //used in histogram
    vector<int> nextSmaller(vector<int> vec){
        
        stack<int> st;
        vector<int> rightSmaller(vec.size(),0);
        
        for(int i = vec.size()-1;i>=0;i--){
            
            //remove all the element greater to the right from stack
            while(!st.empty() && vec[st.top()] >= vec[i])
                st.pop();
            
            //assign the answer
            if(st.empty())
                rightSmaller[i] = -1;
            else
                rightSmaller[i] = st.top();
            
            //push the current value to the stack
            st.push(i);
            
        }
        
        return rightSmaller;
    }
    
    //used in histogram
    vector<int> prevSmaller(vector<int> vec){
        
        stack<int> st;
        vector<int> leftSmallest(vec.size(),0);
        
        for(int i = 0;i<vec.size();i++){
            
            //remove all the elements greater to the left from stack
            while(!st.empty() && vec[st.top()] >= vec[i])
                st.pop();
            
            //assign answer
            if(st.empty())
                leftSmallest[i] = -1;
            else
                leftSmallest[i] = st.top();
            
            //push the current element
            st.push(i);

        }
        
        return leftSmallest;
    }
    
    int areaOfHistogram(vector<int> vec){
        
        //get the prevSmaller and nextSmaller for every element
        vector<int> left = prevSmaller(vec);
        vector<int> right = nextSmaller(vec);
        
        int maxArea = 0;
        
        for(int i = 0;i<vec.size();i++){
            
            //get length and breadth
            if(right[i] == -1)
                right[i] = vec.size();
            
            int length = right[i] - left[i] - 1;
            int breadth = vec[i];
            
            //calculate area
            int area = length*breadth;
            
            //store the maximum area
            maxArea = max(area,maxArea);
            
        }
        
        return maxArea;
        
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int raws = matrix.size();
        int cols = matrix[0].size();
        
        //since it will be a vector of char, we keep a temporary vector of int
        //to pass that into areaOfHistogram
        
        vector<int> temp(cols,0);
        int maxArea = 0;
        
        for(int i = 0;i<raws;i++){
            
            //go for the whole raw
            for(int j = 0;j<cols;j++){
                
                if(matrix[i][j] == '1')
                    temp[j] += 1;
                else
                    temp[j] = 0;
                                
            }
            
            //find the area of Histogram for this raw
            int area = areaOfHistogram(temp);
            
            //store the maximum area
            maxArea = max(area,maxArea);
            
        }
        
        return maxArea;
    }
};