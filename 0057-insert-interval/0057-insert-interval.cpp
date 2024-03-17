class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        //insert newInterval at the appropriate place
        
        vector<vector<int>> vec;
        
        for(auto it : intervals){
            
            if(it[0] <= newInterval[0])
                vec.push_back(it);
            else
                break;
            
            
        }
        
        vec.push_back(newInterval);
        
        for(auto it : intervals){
            
            if(it[0] > newInterval[0])
                vec.push_back(it);
            
        }
        
        //merge the intervals if needed
        vector<vector<int>> ans;
        pair<int,int> p = {vec[0][0],vec[0][1]};
        
        for(auto it : vec){
            
            if(it[0] <= p.second){//if overlaps
                
                p.second = max(p.second,it[1]);
                
            }else{
                
                //push the current pair into ans and start pairing from this index
                ans.push_back({p.first,p.second});
                p = {it[0],it[1]};
                
            }
            
        }
        
        ans.push_back({p.first,p.second});
        
        return ans;
        
    }
};