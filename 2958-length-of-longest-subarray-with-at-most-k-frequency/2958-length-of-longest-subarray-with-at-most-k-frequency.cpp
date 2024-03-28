class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int left = 0;
        map<int,int> freq;
        
        int maxi = 0;
            
        for(int right = 0;right<nums.size();right++){
            
            freq[nums[right]]++;
            
            while(left <= right && freq[nums[right]] > k){
                
                freq[nums[left]]--;
                left++;
                
            }
            
            // cout<<left<<" "<<right<<endl;
            
            maxi = max(maxi,right-left+1);
            
        }
        
        return maxi;
            }
};