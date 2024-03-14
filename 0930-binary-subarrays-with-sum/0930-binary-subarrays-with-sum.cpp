class Solution {
public:
    
    int atMost(vector<int> nums,int goal){
        
        int left = 0;
        int right = 0;
        
        int sum = 0;
        int ans = 0;
        
        while(right < nums.size()){
            
            sum += nums[right];
            
            while(sum > goal && left <= right)
                sum -= nums[left++];
            
            ans += (right-left+1);
            
            right++;
        }
        
        return ans;
        
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atMost(nums,goal)-atMost(nums,goal-1);
        
    }
};