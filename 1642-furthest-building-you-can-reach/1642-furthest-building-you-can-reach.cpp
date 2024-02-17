class Solution {
public:
    
    bool isPossible(vector<int> heights,int bricks,int ladders,int mid){
        
        vector<int> vec;
                
        for(int i = 1;i<=mid;i++){
            
            int diff = heights[i] - heights[i-1];
            
            if(diff > 0)
                vec.push_back(diff);
            
        }
        
        sort(vec.begin(),vec.end());
        
        for(int i : vec){
            
            if(i<=bricks){
                bricks -= i;
            }else if(ladders > 0){
                ladders--;
            }else{
                return false;
            }
            
        }
        
        return true;
        
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int start = 0;
        int end = heights.size()-1;
        int ans = -1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(isPossible(heights,bricks,ladders,mid)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
            
        }
        
        return ans;
        
    }
};