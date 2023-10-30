class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //edge cases
        if(nums.size() <= 1)
            return true;
        
        //if we cannot move anywhere from the first index itself
        if(nums[0] == 0)
            return false;
        
        int n = nums.size();
        
        //keep track of three things
        
        int steps = nums[0];//steps I can take
        int maxReach = nums[0];//till where I can reach
        
        for(int i = 1;i<n;i++){
            
            //if I have reached the last index
            if(i == n-1)
                return true;
            
            //update the maximum reach we can go
            maxReach = max(maxReach, i+nums[i]);
            steps--;//we took one step
            
            //if we cannot move further with the current steps
            if(steps == 0){
                                
                //check if we can take further steps
                
                if(i == maxReach)// we cannot take steps since we are in maxReach already
                    return false;
                else
                    steps = maxReach - i;//we can take (maxReach - current position) steps ahead
                
            }
            
        }
         
        return false;
    }
};