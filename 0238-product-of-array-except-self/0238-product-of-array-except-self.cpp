class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int product = 1;
        int zeros = 0;
        int zeroIndex = -1;
        
        for(auto i : nums){
            
            if(i==0)zeros++;
            product*=i;
            
        }
        
        if(product == 0){
            
            vector<int> ans(nums.size(),0);
            
           if(zeros>1){
               return ans;
           }else{
               
               int prod = 1;
               
             for(int i = 0;i<nums.size();i++){
                 if(nums[i]==0)zeroIndex = i;
                 else 
                     prod = prod*nums[i];
             }
             ans[zeroIndex] = prod;
             return ans;
               
           }
            
        }else{
            
             
            vector<int> ans;

            for(int i = 0;i<nums.size();i++){

                ans.push_back(product/nums[i]);

            }

            return ans;

            
        }
       
    }
};