class Solution {
public:
    
    int atMost(vector<int> nums,int odds){
        
        int left = 0;
        int oddCount = 0;
        
        int count = 0;
        
        for(int right = 0;right<nums.size();right++){
            
            if(nums[right] & 1)
                oddCount++;
            
            while(oddCount > odds){
                
                if(nums[left] & 1)
                    oddCount--;
                
                left++;
                
            }
            
            count += (right - left + 1);
            
        }
        
        return count;
        
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int ans = atMost(nums,k) - atMost(nums,k-1);
        
        return ans;
        
    }
};