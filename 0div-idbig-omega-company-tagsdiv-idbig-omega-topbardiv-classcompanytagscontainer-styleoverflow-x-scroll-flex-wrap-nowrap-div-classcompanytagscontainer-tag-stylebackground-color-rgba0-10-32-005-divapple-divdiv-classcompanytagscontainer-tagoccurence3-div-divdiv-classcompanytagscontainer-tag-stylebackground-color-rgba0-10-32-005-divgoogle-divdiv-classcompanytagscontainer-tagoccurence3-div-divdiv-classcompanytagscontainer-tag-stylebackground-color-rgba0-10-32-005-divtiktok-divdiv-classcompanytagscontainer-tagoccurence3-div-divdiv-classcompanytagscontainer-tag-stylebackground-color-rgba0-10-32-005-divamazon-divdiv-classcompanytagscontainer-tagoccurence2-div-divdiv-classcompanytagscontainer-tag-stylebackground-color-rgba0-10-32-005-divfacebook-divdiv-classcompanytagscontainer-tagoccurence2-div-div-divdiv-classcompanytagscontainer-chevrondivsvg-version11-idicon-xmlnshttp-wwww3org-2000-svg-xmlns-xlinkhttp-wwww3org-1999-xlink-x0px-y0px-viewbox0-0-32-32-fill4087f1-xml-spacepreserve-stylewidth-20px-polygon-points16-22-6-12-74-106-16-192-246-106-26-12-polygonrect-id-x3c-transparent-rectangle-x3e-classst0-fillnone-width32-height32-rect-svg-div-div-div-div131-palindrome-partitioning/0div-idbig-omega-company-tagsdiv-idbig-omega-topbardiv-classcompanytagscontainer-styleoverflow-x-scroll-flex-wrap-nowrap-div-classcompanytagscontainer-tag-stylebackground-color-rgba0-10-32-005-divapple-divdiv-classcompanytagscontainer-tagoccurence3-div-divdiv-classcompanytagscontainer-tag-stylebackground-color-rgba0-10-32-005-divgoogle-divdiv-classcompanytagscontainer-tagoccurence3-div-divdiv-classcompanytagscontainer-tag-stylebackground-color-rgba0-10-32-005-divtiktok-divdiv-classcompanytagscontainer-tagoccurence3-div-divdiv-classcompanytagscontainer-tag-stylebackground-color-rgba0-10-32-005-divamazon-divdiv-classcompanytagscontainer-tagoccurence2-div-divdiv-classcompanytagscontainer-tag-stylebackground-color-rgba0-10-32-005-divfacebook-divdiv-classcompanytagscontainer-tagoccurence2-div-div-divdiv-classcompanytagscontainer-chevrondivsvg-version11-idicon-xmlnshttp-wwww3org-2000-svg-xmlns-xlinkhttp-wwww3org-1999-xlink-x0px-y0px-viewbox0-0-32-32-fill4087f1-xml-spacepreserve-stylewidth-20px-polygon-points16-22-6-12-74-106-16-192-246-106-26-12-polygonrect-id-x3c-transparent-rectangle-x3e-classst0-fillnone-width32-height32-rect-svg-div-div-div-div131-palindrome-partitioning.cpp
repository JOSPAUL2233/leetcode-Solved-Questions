class Solution {
public:
    
    bool isPalindrome(string s,int left,int right){
        
        while(left < right){
            
            if(s[left] != s[right])
                return false;
            
            left++;
            right--;
        }
        
        return true;
        
    }
    
    void solve(string s,int index,vector<string> path,vector<vector<string>> &ans){
        
        //base case
        if(index == s.size()){
            
            ans.push_back(path);
            return;
            
        }
        
        //recursion for partision
        for(int i = index;i<s.size();i++){
            
            if(isPalindrome(s,index,i)){
                
                path.push_back(s.substr(index,i-index+1));
                solve(s,i+1,path,ans);
                path.pop_back();
                
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> path;
        vector<vector<string>> ans;
        
        int index = 0;
        
        solve(s,index,path,ans);
        
        return ans;
        
    }
};