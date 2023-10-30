class Solution {
public:
    int jump(vector<int>& nums) {
        
        //edge cases
        if(nums.size() <= 1)
            return 0;
        
        //if we cannot move anywhere from the first index itself
        if(nums[0] == 0)
            return -1;
        
        int n = nums.size();
        
        //keep track of three things
        
        int steps = nums[0];//steps I can take
        int maxReach = nums[0];//till where I can reach
        int jumps = 1;//if I reach at the end from first location, I took one jump
        
        for(int i = 1;i<n;i++){
            
            //if I have reached the last index
            if(i == n-1)
                return jumps;
            
            //update the maximum reach we can go
            maxReach = max(maxReach, i+nums[i]);
            steps--;//we took one step
            
            //if we cannot move further with the current steps
            if(steps == 0){
                
                jumps++;//take a jump
                
                //check if we can take further steps
                
                if(i == maxReach)//if we are in maxReach already
                    return -1;
                else
                    steps = maxReach - i;//we can take (maxReach - current position) steps ahead
                
            }
            
            
        }
         
        return -1;
        
    }
};