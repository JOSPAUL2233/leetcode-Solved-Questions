class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int ans = -1;
        int minDiff = INT_MAX;
        
        for(int left = 0;left<nums.size();left++){
            
            int mid = left+1;
            int right = nums.size()-1;
            
            while(mid<right){
                
                int sum = nums[left] + nums[mid] + nums[right];
                
                int currDiff = abs(sum - target);
                
                if(currDiff < minDiff){
                    
                    ans = sum;
                    minDiff = currDiff;
                    
                }
                
                if(sum < target){
                    
                    mid++;
                    
                }else{
                    
                    right--;
                    
                }
                   
            }
            
        }
        
        return ans;
        
    }
};