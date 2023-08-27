class Solution {
public:
    
//     bool sumIsEqual(vector<int> arr,int n){
        
//         //get the sum
//         int sum = 0;
//         for(int i = 0;i<arr.size();i++)
//             sum += arr[i];
        
//         //check if it is equal
//         if(sum == n)
//             return true;
//         else
//             return false;
        
//     }
    
    void solve(int val,vector<int> path,vector<vector<int>> &ans,int k,int n,int sum){
        
        //base case
        if(path.size() == k){
            
            if(sum == n){
                
                ans.push_back(path);
                
            }
            
            return;
            
        }
        
        
        //loop throughout the nums ( from current value till 9 )
        for(int i = val ; i<=9 ; i++){
            
            sum += i;
            path.push_back(i);
            solve(i+1,path,ans,k,n,sum);
            path.pop_back();
            sum -= i;
                        
        }
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        // vector<int> nums = {1,2,3,4,5,6,7,8,9};
        
        int val = 1;
        
        vector<int> path;
        vector<vector<int>> ans;
        
        int sum = 0;
        
        solve(val,path,ans,k,n,sum);
        
        return ans;
        
    }
};