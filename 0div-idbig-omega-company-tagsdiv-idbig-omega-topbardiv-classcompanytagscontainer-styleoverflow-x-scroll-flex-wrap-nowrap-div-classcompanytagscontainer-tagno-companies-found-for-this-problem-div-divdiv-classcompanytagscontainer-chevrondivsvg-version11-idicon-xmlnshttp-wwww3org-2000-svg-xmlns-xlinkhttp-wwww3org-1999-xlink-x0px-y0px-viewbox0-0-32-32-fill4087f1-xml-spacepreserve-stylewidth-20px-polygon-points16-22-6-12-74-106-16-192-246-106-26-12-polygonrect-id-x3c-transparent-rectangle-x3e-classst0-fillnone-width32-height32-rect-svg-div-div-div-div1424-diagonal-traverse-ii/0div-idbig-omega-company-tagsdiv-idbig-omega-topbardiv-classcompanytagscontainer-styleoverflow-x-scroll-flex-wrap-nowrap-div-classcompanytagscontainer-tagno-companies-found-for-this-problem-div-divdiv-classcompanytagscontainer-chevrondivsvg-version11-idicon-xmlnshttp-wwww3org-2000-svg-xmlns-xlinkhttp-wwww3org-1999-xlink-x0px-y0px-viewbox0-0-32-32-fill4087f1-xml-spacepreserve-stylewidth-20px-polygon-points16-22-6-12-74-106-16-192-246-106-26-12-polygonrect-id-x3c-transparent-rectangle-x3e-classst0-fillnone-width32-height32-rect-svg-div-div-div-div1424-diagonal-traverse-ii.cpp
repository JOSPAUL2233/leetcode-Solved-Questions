class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        queue<pair<int,int>> que;
        
        que.push({0,0});
        
        vector<int> ans;
        
        while(!que.empty()){
            
            
            int size = que.size();
            
            for(int i = 0;i<size;i++){
                
                auto p = que.front();
                que.pop();
                                
                int r = p.first;
                int c = p.second;
                
                ans.push_back(nums[r][c]);
                
                //push bottom
                if(r+1 < nums.size() && c == 0){
                
                    que.push({r+1,c});
                    
                }
                
                // push right
                if(c+1 < nums[r].size()){
                    
                    que.push({r,c+1});
                    
                }
                
            }
            
            
        }
        
        return ans;
        
    }
};