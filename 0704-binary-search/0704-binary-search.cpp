class Solution {
public:
    
    int binarySearch(vector<int> &nums,int target,int start,int end){
        
        if(start > end)
            return -1;
        
        int mid = start +(end - start)/2;
        cout<<mid<<endl;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid] > target)
            return binarySearch(nums,target,start,mid-1);
        else
            return binarySearch(nums,target,mid+1,end);
        
    }
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        
//         while(start <= end){
            
//             int mid = start + (end - start)/2;
            
//             if(nums[mid] == target)
//                 return mid;
            
//             if(nums[mid] < target)
//                 start = mid+1;
//             else
//                 end = mid-1;
            
//         }
        
        int ans = binarySearch(nums,target,start,end);
        
        return ans;
        
    }
};