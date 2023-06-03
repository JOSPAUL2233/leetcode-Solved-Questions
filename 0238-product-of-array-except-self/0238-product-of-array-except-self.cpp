class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefix(nums.size(),0);
        vector<int> postfix(nums.size(),0);
        vector<int> ans(nums.size(),0);
        
        int product = 1;
        
        //assign the prefix values as the
        //product of left elements
        for(int i = 0;i<nums.size();i++){
            
            product *= nums[i];
            
            prefix[i] = product;
            
        }
        
        product = 1;
        
        //assign the postfix values as the
        //product of right elements
        for(int i = nums.size()-1;i>=0;i--){
            
            product *= nums[i];
            
            postfix[i] = product;
            
        }
        
        //now multiply the left and right of the 
        //prefix and postfix array to find the
        //product except the current element
        
        //calculate for 1st and last element
        ans[0] = postfix[1];
        ans[nums.size()-1] = prefix[nums.size()-2];
        
        for(int i = 1;i<nums.size()-1;i++){
            
            ans[i] = prefix[i-1] * postfix[i+1];
            
        }
        
        return ans;
    }
};