class Solution {
    
    void solve(vector<int> nums,int index,vector<int> subset,vector<vector<int>>& ans){
        
        //if the subset is made
        if(index == nums.size()){
            
            ans.push_back(subset);
            return;
            
        }
        
        //exclude
        solve(nums,index+1,subset,ans);
        
        //include
        subset.push_back(nums[index]);
        solve(nums,index+1,subset,ans);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        int index = 0;
        
        solve(nums,index,subset,ans);
        
        return ans;
        
    }
};