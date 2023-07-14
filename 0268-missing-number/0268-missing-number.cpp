class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //here, zero indexing is followed
        //means, the numbers are from 0 to n
        
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            
            //XORing i and the element
            ans ^= (nums[i]^i);
            
        }
        
        
        ans^=n;
        
        return ans;
        
    }
};