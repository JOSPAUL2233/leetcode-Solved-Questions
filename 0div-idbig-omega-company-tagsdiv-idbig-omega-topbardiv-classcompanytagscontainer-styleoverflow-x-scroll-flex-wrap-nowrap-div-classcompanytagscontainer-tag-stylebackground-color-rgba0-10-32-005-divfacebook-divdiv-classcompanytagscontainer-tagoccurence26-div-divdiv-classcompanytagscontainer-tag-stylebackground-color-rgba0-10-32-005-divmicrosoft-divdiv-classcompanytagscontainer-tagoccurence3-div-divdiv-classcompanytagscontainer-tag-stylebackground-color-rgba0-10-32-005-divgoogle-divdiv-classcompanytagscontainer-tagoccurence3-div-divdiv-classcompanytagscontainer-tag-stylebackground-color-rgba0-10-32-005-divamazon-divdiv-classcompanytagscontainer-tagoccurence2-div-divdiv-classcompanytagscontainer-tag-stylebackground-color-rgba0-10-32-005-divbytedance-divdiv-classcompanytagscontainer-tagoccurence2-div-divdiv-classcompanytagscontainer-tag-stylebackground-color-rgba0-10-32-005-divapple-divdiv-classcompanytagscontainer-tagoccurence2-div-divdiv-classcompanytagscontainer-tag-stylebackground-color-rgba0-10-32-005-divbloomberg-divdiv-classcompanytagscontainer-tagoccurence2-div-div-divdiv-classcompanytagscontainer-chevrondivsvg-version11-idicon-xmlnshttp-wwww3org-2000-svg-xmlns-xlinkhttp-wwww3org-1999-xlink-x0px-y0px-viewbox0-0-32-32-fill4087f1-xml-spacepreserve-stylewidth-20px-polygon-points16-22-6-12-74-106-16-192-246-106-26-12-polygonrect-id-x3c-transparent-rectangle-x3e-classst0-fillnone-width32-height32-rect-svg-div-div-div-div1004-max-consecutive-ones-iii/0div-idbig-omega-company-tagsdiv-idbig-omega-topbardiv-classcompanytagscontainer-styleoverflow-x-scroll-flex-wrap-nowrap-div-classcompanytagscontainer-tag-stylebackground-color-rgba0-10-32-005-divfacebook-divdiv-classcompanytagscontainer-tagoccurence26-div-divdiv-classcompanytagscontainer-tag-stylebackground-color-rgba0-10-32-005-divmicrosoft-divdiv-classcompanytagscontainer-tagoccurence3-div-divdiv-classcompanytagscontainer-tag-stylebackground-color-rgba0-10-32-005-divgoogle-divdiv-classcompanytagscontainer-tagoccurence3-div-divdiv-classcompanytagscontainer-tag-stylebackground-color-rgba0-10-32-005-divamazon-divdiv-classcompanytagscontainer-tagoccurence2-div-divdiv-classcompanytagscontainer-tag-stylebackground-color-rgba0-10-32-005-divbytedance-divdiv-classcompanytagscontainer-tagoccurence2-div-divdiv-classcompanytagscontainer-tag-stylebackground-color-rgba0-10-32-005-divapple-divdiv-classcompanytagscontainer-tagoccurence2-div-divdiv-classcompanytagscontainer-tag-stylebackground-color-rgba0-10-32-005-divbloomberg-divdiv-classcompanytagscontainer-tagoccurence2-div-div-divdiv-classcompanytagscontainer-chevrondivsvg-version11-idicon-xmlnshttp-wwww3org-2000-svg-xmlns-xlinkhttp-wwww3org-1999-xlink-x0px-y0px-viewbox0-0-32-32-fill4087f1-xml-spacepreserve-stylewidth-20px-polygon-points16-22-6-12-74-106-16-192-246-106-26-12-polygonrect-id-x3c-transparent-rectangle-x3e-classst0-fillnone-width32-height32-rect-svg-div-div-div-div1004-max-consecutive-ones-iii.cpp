class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left = 0;
        int maxCount = INT_MIN;
        
        for(int right = 0;right<nums.size();right++){
            
            //if current element is zero
            if(nums[right] == 0)
                k--;
            
            //shrink window till k becomes zero or greater
            while(k < 0){
                
                //increase k if left encounters with zero
                if(nums[left] == 0)
                    k++;
                
                left++;
            }
            
            //store the maximum count
            int count = right - left + 1;
            maxCount = max(maxCount,count);
            
        }
        
        return maxCount;
        
    }
};