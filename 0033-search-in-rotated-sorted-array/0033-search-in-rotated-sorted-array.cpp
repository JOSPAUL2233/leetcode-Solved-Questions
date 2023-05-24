class Solution {
    
    int binarySearch(vector<int>& nums,int start,int end,int target){
        
        while(start<=end){
            
            int mid = start+(end-start)/2;

            if(nums[mid] == target)return mid;
            
            if(nums[mid]<target){
                start = mid+1;
            }else{
                end = mid-1;
            }
            
        }
        
        return -1;
        
    }
    
    int getPivot(vector<int>& nums){
        
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start<end){
            
            int mid = start+(end-start)/2;
            
            if(nums[mid] >= nums[0]){
                
                start = mid+1;
                
            }else{
                end = mid;
            }
            
        }
        return start;
        
    }
    
public:
    int search(vector<int>& nums, int target) {
        
        int start = -1;
        int end = -1;
        
        //find the pivot index
        
        int pivot = getPivot(nums);
    
        
        //check which target side ----- left side [or] right side of pivot(includes pivot)
        
        if(target >= nums[pivot] && target<=nums[nums.size()-1]){
            start = pivot;
            end = nums.size()-1;
        }else{
            start = 0;
            end = pivot-1;
        }
        
        //go for binary search
                                
        int ans = binarySearch(nums,start,end,target);
        
        return ans;
        
    }
};