class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> ans(n,0);
        
        int highest = -1;
        
        for(int i = n-1;i>=0;i--){
            
            //check if the element itself is the highest,
            //which means, there is no highest value to the right of that element
            if(temperatures[i] >= highest){
                
                highest = temperatures[i];
                ans[i] = 0;
            
            }else{
                
                //keep a gap of 1 day at first
                int days = 1;
                
                while(temperatures[i+days] <= temperatures[i]){
                    
                    //then go to next greater value
                    days += ans[i+days];
                    
                }
                
                //store the next greater value
                ans[i] = days;
                
            }
            
        }
        
        return ans;
        
    }
};