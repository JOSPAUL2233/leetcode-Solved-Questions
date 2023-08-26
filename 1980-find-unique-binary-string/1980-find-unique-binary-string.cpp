class Solution {
public:
    
    void solve(int num, string path,vector<string> nums,string &ans){
        
        if(ans.size() != 0)
            return;
        
        //base case
        if(path.size() == num){
            
            //check if path is there in the 
            for(int i = 0;i<nums.size();i++){
                
                if(nums[i] == path)
                    return;
                
            }
            
            ans = path;
            return;
            
        }
        
        path.push_back('0');//put zero
        solve(num,path,nums,ans);//recursive call
        path.pop_back();//remove zero while backtracking
        
        path.push_back('1');//put 1
        solve(num,path,nums,ans);//recursive call
        path.pop_back();//remove one while backtracking
        
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        string path = "";
        
        string ans = "";
        
        solve(nums[0].size(),path,nums,ans);
        
        return ans;
        
    }
};