class Solution {
public:
    
    void solve(vector<int> candidates, int target, int index,vector<int> path,vector<vector<int>> &ans){
        
        //base case
        if(target == 0){
            
            ans.push_back(path);
            return;
            
        }
                        
        //loop from index till the end
        for(int i = index;i<candidates.size();i++){
            
            
            //ignore the same elements
            if((i > index) && (candidates[i] == candidates[i-1]))
                continue;
            
            //if the value is greater than target, then no need to go for
            //further iteration
            if(candidates[i] > target)
                break;
            
            //carry on with the further recursion
            path.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, path, ans);
            path.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        //sort the array
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> path;
        
        int index = 0;
        
        solve(candidates,target,index,path,ans);
        
        return ans;
        
    }
};