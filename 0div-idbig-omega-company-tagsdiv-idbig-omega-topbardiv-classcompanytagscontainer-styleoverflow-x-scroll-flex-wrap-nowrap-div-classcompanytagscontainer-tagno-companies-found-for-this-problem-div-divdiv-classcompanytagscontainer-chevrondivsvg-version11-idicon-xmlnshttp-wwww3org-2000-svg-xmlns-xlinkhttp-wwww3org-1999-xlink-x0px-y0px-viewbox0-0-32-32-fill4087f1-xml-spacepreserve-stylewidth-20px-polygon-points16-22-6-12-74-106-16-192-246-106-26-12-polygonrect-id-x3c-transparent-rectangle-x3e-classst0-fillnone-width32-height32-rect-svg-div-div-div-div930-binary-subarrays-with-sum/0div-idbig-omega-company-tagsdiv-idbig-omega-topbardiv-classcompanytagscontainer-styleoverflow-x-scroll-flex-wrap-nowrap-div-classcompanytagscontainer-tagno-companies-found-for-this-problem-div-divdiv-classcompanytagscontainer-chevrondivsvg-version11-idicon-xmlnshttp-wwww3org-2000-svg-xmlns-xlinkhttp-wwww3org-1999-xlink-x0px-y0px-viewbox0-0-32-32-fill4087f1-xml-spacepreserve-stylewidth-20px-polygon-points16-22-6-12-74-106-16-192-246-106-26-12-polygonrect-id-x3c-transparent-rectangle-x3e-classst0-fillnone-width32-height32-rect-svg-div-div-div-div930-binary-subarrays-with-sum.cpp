class Solution {
public:
    
    int countSubArr(vector<int> nums,int goal){
        
        if(goal < 0)
            return 0;
        
        int sum = 0;
        int count = 0;
        
        int left = 0;
        
        for(int right = 0;right<nums.size();right++){
            
            //add the current element into the sum
            sum += nums[right];
            //shrink the subArray if the sum is exceeding goal
            while(sum > goal){
                
                sum -= nums[left];
                left++;
                
            }
            
            //this counts the subarrays in that window.
            count += (right - left + 1);
        }
        
        return count;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //number of sub arrays with at most sum (goal) - number of
        //sub arrays with at most sum (goal-1)
        //sub array with sum goal will be found
        
        int ans = countSubArr(nums,goal) - countSubArr(nums,goal-1);
        
        return ans;
        
    }
};