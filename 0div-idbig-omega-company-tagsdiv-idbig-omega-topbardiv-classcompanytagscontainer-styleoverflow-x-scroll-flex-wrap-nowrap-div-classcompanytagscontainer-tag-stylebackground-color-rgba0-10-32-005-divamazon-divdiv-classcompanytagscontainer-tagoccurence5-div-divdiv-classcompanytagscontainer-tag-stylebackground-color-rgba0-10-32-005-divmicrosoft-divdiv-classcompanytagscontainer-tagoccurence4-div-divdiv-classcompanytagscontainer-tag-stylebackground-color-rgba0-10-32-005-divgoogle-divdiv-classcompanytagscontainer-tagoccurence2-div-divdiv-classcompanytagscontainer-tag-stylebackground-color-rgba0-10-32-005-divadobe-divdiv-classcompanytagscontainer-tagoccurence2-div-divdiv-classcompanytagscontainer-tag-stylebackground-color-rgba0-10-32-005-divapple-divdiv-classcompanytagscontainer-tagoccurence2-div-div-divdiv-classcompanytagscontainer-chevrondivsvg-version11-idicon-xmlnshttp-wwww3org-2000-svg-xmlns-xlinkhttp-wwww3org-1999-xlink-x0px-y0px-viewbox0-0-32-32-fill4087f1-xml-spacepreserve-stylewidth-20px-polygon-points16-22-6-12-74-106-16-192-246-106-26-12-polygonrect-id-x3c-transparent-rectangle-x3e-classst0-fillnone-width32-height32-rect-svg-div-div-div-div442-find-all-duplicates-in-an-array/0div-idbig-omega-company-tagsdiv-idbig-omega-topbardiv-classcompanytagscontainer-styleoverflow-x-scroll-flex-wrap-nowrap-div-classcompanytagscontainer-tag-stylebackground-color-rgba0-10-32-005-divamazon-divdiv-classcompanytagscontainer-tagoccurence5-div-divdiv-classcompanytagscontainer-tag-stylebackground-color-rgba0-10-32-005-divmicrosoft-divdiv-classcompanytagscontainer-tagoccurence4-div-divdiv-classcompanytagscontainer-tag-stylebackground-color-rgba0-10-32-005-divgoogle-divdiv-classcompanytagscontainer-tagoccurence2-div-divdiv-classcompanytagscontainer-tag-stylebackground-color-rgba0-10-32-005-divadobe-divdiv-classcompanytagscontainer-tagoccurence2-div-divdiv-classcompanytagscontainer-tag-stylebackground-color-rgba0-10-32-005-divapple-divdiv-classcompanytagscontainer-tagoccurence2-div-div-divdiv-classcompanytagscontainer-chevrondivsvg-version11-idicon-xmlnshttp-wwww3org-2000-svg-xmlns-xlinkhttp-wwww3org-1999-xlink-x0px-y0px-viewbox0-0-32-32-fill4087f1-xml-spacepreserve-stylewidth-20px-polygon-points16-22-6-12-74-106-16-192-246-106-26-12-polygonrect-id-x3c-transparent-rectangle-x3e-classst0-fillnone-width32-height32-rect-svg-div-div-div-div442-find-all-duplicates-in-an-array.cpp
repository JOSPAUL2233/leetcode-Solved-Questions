class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int maxi = nums.size()+1;
        
        for(int i = 0;i<nums.size();i++){
            
            int index = (nums[i] % maxi)-1;
            
            nums[index] += maxi;
            
        }
        
        vector<int> ans;
        
        for(int i = 0;i<nums.size();i++){
            
            if((nums[i]/maxi) >=2)
                ans.push_back(i+1);
            
        }
        
        return ans;
        
    }
};