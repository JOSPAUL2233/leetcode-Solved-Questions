class Solution {
private:
    
    
    vector<int> nextSmallerElement(vector<int> heights,int n){
        
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(int i = n-1;i>=0;i--){
            
          while(!st.empty()){
              
              //check
                  if(heights[st.top()]<heights[i]){

                      ans[i] = st.top();
                      break;

                  }
              
                st.pop();
              
            }
            
        st.push(i);
            
        }
        
        return ans;
        
    }
    
    vector<int> prevSmallerElement(vector<int> heights,int n){
        
        
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(int i = 0;i<n;i++){
            
            while(!st.empty()){
                
                //check
                if(heights[st.top()]<heights[i]){
                    
                    ans[i] = st.top();
                    break;
                    
                }
                
                st.pop();
            }
            
            st.push(i);
            
        }
        
        return ans;
        
    }
    
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> next = nextSmallerElement(heights,n);
        vector<int> prev = prevSmallerElement(heights,n);
        
        int area = 0;
        
        for(int i = 0;i<n;i++){
            
            int l = heights[i];
            
            if(next[i]==-1)next[i] = n;
            
            int b = next[i]-prev[i]-1;
            
            int compareArea = l*b;
            area = max(area,compareArea);
            
        }
        
        return area;
        
    }
};