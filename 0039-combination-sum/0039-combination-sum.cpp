class Solution {
    
    
    void solve(vector<int> candidate,int target,int index,vector<int> container,vector<vector<int>> &ans){
        
        
        if(index==candidate.size()){
            
            if(target==0){
                
                ans.push_back(container);
                return;
            }
            else return;
            
        }
        
        //pick
        if(target>=candidate[index]){
            
            container.push_back(candidate[index]);
            target -= candidate[index];
            solve(candidate,target,index,container,ans);
            target += candidate[index];
            container.pop_back();
        
        }
        
        
        //not pick
        solve(candidate,target,index+1,container,ans);
        
        
        
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        
        
        int index = 0;
        int sum = 0;
        
        vector<vector<int>> ans;
        
        vector<int> container;
        
        solve(candidate,target,index,container,ans);
        
        
        return ans;
        
    }
};