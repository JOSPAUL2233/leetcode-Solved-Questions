class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        //understand the intuition
        
        int prefix = 1;
        int suffix = 1;
        
        int maxi = INT_MIN;
        
        for(int i = 0;i<n;i++){
            
            //if the prefix or suffix becomes zero,
            //make it 1 so that it can start from
            //that point
            
            if(prefix == 0)
                prefix = 1;
            
            if(suffix == 0)
                suffix = 1;
            
            prefix *= nums[i];
            suffix *= nums[n-1-i];
            
            //store the maximum product value
            maxi = max(maxi, max(prefix,suffix));
            
        }
        
        return maxi;
        
    }
};