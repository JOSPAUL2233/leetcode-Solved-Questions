class Solution {
public:
    
    
    
    
    bool isPossible(vector<int> nums,int mid,int p){
        
        int count = 0;
        
        for(int i = 1;i<nums.size();i++){
            
            if((nums[i] - nums[i-1]) <= mid){
                
                count++;
                i++;
                
            }
            
        }
        
        if(count >= p)
            return true;
        else
            return false;
        
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        
        int start = 0;
        int end = nums[nums.size()-1] - nums[0];
        
        int ans = -1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(nums,mid,p)){
                
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
            
        }
        
        
        return ans;
        
    }
};