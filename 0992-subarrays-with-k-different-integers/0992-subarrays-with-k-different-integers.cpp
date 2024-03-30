class Solution {
public:
    
    int atMost(vector<int>& nums,int k){
        
        int n = nums.size();
        
        int left = 0;
        int right = 0;
        
        int count = 0;
        
        map<int,int> freq;
        
        while(right<n){
            
            freq[nums[right]]++;
            
            while(left<=right && freq.size() > k){
                
                freq[nums[left]]--;
                    
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                
                left++;
            }
            
            count += (right-left+1);
            
            right++;
        }
        
        return count;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};