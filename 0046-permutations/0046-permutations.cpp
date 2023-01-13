class Solution {
public:
    
    
    void solve(vector<int> nums,vector<vector<int>>& ans,int index){
        
        
        if(index>=nums.size()){
            
            ans.push_back(nums);
            return;
            
        }
        
        
        
        for(int i = index;i<nums.size();i++){
        
            //swapping
            
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
            
            solve(nums,ans,index+1);
            
            temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
            
            
            
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int index = 0;
        
        solve(nums,ans,index);
        
        return ans;
        
    }
};