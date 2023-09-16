class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left = 0;
        int maxCount = INT_MIN;
        
        int zeroCount = 0;
        
        for(int right = 0;right<nums.size();right++){
            
            //if current element is zero, increase the zeroCount
            if(nums[right] == 0)
                zeroCount++;
            
            //shrink window till zeroCount becomes greater than or equals to k
            while(zeroCount > k){
                
                //increase k if left encounters with zero
                if(nums[left] == 0)
                    zeroCount--;
                
                left++;
            }
            
            //store the maximum count
            int count = right - left + 1;
            maxCount = max(maxCount,count);
            
        }
        
        return maxCount;
        
    }
};