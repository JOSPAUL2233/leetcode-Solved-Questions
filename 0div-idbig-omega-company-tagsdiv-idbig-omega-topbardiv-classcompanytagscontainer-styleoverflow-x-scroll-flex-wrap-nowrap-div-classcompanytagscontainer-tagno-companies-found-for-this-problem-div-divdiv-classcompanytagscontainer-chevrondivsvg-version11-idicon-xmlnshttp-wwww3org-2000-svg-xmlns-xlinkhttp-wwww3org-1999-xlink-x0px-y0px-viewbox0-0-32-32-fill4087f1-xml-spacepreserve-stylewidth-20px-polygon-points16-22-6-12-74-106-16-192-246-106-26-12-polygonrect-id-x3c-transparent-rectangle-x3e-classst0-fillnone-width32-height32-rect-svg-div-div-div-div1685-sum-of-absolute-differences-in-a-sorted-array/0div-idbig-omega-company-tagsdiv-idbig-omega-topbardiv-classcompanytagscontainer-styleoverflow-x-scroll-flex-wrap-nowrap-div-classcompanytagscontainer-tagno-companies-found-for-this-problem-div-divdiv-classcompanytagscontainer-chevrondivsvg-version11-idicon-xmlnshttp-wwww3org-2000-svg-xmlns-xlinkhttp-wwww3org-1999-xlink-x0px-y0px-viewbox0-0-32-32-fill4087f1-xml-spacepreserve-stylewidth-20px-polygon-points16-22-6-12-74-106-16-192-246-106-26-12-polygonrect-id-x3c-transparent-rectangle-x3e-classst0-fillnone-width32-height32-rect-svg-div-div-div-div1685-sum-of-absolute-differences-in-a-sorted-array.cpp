class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        
        //maintain seperate prefix and suffix sum
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
        
        //now, computer the answer seperately using prefix and suffix sum in calculation
        //inorder to overcome negative values.
        
        vector<int> ans(n,-1);
        
        for(int i = 0;i<nums.size();i++){
            
            int leftCount = i;//number of elements present left side of ith position
            int rightCount = n-i;//number of elements present right side of ith position including the ith element
            
            ans[i] = ((nums[i] * leftCount) - prefixSum[i]) + (suffixSum[i] - ( nums[i] * rightCount));
            
        }
        
        return ans;
        
    }
};