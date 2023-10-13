class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size()-1;
        
        int minEle = INT_MAX;
        
        while(left <= right){
            
            int mid = left + (right - left)/2;
            
            //check which part is sorted
            if(nums[left] <= nums[mid]){
                
                minEle = min(minEle,nums[left]);
                left = mid+1;
                
                
            }else{
                
                minEle = min(minEle,nums[mid]);
                right = mid-1;
                
            }
            
            
        }
        
        return minEle;
        
    }
};