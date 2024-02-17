class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int,vector<int>, greater<int>> pq;//MIN HEAP
        
        for(int i = 1;i<heights.size();i++){
            
            int diff = heights[i] - heights[i-1];
            
            if(diff > 0){
                
                pq.push(diff);
                
                if(pq.size() > ladders){
                    
                    int ele = pq.top();
                    pq.pop();
                                        
                    if(bricks >= ele){
                        bricks -= ele;                        
                    }else{
                        return i-1;
                    }
                    
                }
                
            }
            
        }
        
        return heights.size()-1;
        
    }
};