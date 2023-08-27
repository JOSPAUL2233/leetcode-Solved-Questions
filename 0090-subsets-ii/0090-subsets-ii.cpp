class Solution {
public:
    
    void solve(vector<int> nums,int index,vector<int> path,vector<vector<int>> &ans){
        
        //store the subset
        ans.push_back(path);
        
        //loop for further positions decisions
        
        for(int i = index;i<nums.size();i++){
            
            //skip the duplicates
            if(i > index && nums[i] == nums[i-1])
                continue;
            
            //continue with recursion call
            path.push_back(nums[i]);
            solve(nums,i+1,path,ans);
            path.pop_back();
            
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());//to keep the duplicates together
        
        vector<int> path;
        vector<vector<int>> ans;
        
        int index = 0;
        
        solve(nums,index,path,ans);
        
        return ans;
        
    }
};