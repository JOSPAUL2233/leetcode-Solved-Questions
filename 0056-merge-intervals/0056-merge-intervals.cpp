class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
    
        sort(intervals.begin(),intervals.end());
        
        vector<int> p;
        p.push_back(intervals[0][0]);
        p.push_back(intervals[0][1]);
    
        
        for(int i = 1;i<intervals.size();i++){
            
            
            if(intervals[i][0] <= p[1]){
                
                p[1] = max(p[1],intervals[i][1]);
    
                
            }else{
                
                    ans.push_back(p);
                
                    p[0] = intervals[i][0];
                    p[1] = intervals[i][1];
                
            }
            
        }
        
        ans.push_back(p);
        
        return ans;
        
        
    }
};