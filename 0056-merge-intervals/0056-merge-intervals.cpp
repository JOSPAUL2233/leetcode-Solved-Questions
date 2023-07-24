class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
    
        //sort the vector
        sort(intervals.begin(),intervals.end());
        
        //make a p for current interval and push the first elements into it
        vector<int> p;
        p.push_back(intervals[0][0]);
        p.push_back(intervals[0][1]);
    
        //start iterating from the second vector
        for(int i = 1;i<intervals.size();i++){
            
            //if the first element in the new interval is lesser than the
            //second element in the pair called p
            
            //and check if the second element in the pair is smaller than the
            //second element in new interval
            
            if(intervals[i][0] <= p[1]){ //overlapping happening
                
                p[1] = max(p[1] , intervals[i][1]);
                
            }else{//no overlapping
                
                    //if the interval did not find overlapping,
                    //push the current p and start finding next p from
                    //the current position
                    ans.push_back(p);
                
                    p[0] = intervals[i][0];
                    p[1] = intervals[i][1];
                
            }
            
        }
        
        ans.push_back(p);
        
        return ans;
        
        
    }
};