class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int left = 0;
        int right = 1;
        
        int count = 0;
        
        while(left < nums.size() && right < nums.size()){
            
            int diff = nums[right] - nums[left];
            
            if(diff==k){
                
                count++;
                left++;
                right++;
                
                while(right < nums.size() && nums[right] == nums[right-1])right++;
                                
            }else if(diff<k){
                
                right++;
                
            }else{
                
                left++;
                if(left == right)right++;
                
            }
            
        }
        
        return count;
        
    }
};