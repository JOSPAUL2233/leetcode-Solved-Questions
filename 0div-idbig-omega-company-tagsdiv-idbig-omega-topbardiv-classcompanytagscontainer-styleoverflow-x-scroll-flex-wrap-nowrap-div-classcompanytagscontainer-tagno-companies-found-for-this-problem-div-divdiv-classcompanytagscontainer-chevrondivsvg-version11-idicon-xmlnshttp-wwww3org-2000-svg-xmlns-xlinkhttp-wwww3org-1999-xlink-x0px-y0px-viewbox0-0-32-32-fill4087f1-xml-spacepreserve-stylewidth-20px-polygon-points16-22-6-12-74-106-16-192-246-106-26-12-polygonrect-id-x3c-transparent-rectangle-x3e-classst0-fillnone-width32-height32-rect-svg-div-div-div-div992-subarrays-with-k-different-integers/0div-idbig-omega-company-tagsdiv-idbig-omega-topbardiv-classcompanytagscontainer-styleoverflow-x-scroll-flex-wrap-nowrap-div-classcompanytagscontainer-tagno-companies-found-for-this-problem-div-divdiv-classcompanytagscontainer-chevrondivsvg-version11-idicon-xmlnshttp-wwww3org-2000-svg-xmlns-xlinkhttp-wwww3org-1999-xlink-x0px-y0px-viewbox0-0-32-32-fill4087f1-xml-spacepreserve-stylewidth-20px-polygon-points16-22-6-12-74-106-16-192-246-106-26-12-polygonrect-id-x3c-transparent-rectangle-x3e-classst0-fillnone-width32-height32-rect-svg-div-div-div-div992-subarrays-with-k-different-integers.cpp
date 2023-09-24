class Solution {
public:
    
    int atMost(vector<int> nums,int k){
        
        //edge case
        if(k == 0)
            return 0;
        
        map<int,int> freq;
        
        int left = 0;
        int distEle = 0;
        
        int count = 0;
        
        for(int right = 0;right<nums.size();right++){
            
            freq[nums[right]]++;
            
            if(freq[nums[right]] == 1)
                distEle++;
            
            while(left < right && distEle > k){
                
                freq[nums[left]]--;
                
                if(freq[nums[left]] == 0)
                    distEle--;
                
                left++;
                
            }

            int windowSize = right - left + 1;
            count += windowSize;
            
        }
        
        return count;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int ans = atMost(nums,k) - atMost(nums,k-1);
        
        return ans;
        
    }
};