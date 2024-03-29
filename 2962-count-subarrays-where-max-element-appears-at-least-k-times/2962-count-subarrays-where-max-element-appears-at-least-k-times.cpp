class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int maxEle = 0;
        for(int i : nums) maxEle = max(maxEle,i);
        
        int count = 0;
        
        int left = 0;
        int right = 0;
        
        long long ans = 0;
        
        while(right<n){
            
            if(nums[right] == maxEle)
                count++;
            
            while(left <= right && count>=k){
                
                ans += (n-right);
                
                if(nums[left]==maxEle)
                    count--;
                
                left++;
                
            }
            
            right++;
        }
        
        return ans;
        
    }
};