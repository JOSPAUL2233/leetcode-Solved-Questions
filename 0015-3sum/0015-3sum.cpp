class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int left = 0;left < nums.size();left++){
            
            
            if(left > 0 && nums[left] == nums[left-1])continue;
            
            int mid = left+1;
            int right = nums.size()-1;
            
            while(mid < right){
                
                int sum = nums[left]+nums[mid]+nums[right];
                
                if(sum==0){
                    
                    ans.push_back({nums[left],nums[mid],nums[right]});
                    
                    mid++;
                    right--;
                    
                    while(mid < right && nums[mid] == nums[mid-1])mid++;
                    while(mid < right && nums[right] == nums[right+1])right--;
                    
                }else if(sum < 0){
                    
                    mid++;
                    
                }else{
                    
                    right--;
                    
                }
                   
            }
            
        }
        
        return ans;
        
    }
};