class Solution {
public:
    
    void solve(vector<int> nums,set<vector<int>>& ans,int index)
    {
        
        
        if(index>=nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int i = index;i<nums.size();i++){
            
            swap(nums[index],nums[i]);
            
            solve(nums,ans,index+1);
            
            swap(nums[index],nums[i]);
            
        }
        
          
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        
        set<vector<int>> ans;
        
        int index = 0;
        
        solve(nums,ans,index);
        
        vector<vector<int>> vec(ans.begin(),ans.end());
        
        return vec;
        
    }
};