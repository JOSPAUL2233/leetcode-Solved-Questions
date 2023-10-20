class Solution {
public:
    
    void solve(int index, vector<int> candidates,int target,int sum,vector<int> path,vector<vector<int>> &ans){
        
        //base case
        if(index == candidates.size()){
            
            if(sum == target)
                ans.push_back(path);
            
            return;
            
        }
        
        //return if the sum exceeds target
        if(sum > target)
            return;
        
        //pick
        sum += candidates[index];
        path.push_back(candidates[index]);
        
        solve(index,candidates,target,sum,path,ans);
        
        sum -= candidates[index];
        path.pop_back();
        
        //not pick
        solve(index+1,candidates,target,sum,path,ans);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int sum = 0;
        vector<int> path;
        vector<vector<int>> ans;
        
        int index = 0;
        
        solve(index, candidates,target,sum,path,ans);
        
        return ans;
        
        
    }
};