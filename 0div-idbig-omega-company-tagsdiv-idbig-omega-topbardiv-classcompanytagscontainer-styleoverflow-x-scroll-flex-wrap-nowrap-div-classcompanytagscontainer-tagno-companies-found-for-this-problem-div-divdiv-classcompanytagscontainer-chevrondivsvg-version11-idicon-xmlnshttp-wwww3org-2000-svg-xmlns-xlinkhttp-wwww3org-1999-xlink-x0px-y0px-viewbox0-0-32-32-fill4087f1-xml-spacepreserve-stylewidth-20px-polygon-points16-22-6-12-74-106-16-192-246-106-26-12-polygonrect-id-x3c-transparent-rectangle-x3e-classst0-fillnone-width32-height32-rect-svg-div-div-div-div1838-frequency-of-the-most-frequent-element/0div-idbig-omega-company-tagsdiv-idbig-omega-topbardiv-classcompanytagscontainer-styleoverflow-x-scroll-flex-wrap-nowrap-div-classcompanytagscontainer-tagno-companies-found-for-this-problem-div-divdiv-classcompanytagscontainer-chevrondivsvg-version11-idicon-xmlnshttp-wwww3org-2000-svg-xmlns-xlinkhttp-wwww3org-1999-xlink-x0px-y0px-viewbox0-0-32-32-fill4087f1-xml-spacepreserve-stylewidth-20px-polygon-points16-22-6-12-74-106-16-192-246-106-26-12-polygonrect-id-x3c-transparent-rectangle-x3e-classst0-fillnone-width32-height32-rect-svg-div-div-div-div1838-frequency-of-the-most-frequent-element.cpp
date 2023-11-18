class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        long long maxLength = 0;
        long long prefixSum = k;
        
        int left = 0;
        
        for(int right = 0;right<nums.size();right++){
            
            long long len = right - left + 1;
            long long target = nums[right] * len;//the target which needs to be achieved
            
            prefixSum += nums[right];//actual value we have
            
            //shrink the search space if needed
            while(left < right && prefixSum < target){
                
                //shrink from back
                prefixSum -= nums[left++];
                
                //accordingly update the length and the target
                len = right - left + 1;
                target = nums[right] * len;
                
            }
            
            //store the maximum length of valid window
            maxLength = max(len,maxLength);
            
        }
        
        return maxLength;
        
    }
};