class Solution {
public:
    
    int atMost(vector<int>& nums,int k){
        
        int n = nums.size();
        
        int left = 0;
        int right = 0;
        int distInt = 0;
        
        int count = 0;
        
        map<int,int> freq;
        
        while(right<n){
            
            if(freq[nums[right]]==0)
                distInt++;
            
            freq[nums[right]]++;
            
            while(left<=right && distInt > k){
                
                //remove one element from left
                freq[nums[left]]--;
                
                //erase the element if it entirely got removed
                if(freq[nums[left]]==0){
                    distInt--;
                }
                
                left++;
            }
            
            //count the number of subarrays with this length
            count += (right-left+1);
            
            right++;
        }
        
        return count;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};