class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> prefixSum(n,-1);
        vector<int> suffixSum(n,-1);
                
        int preSum = 0;
        int sufSum = 0;
        
        for(int i = 0;i<n;i++){
            
            prefixSum[i] = preSum;
            preSum += nums[i];
            
            sufSum += nums[n-1-i];
            suffixSum[n-1-i] = sufSum;
            
        }
        
        //now, computer the answer
        vector<int> ans(n,-1);
        
        for(int i = 0;i<nums.size();i++){
            
            ans[i] = ((nums[i] * i) - prefixSum[i]) + (suffixSum[i] - ( nums[i] * (n-i)));
            
        }
        
        return ans;
        
        
    }
};