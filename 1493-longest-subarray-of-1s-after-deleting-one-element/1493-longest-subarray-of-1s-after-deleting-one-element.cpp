class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        //sliding window approach
        int left = 0;
        
        int countZero = 0;
        int maxLen = 0;
        
        for(int right = 0;right < nums.size();right++){
            
            if(nums[right] == 0)
                countZero++;
            
            //shorten window from left side till there are only one zero
            while(countZero > 1){
                
                if(nums[left] == 0)countZero--;
                left++;
            }
            
            //store maximum maxLen
            //left - right + 1 for total length we do -1 to remove one element from it.
            maxLen = max(maxLen , right - left);
            
        }
        
        return maxLen;
        
    }
};