class Solution {
public:
    
    bool isPalindrome(string s,int start,int end){
        
        while(start <= end){
            
            if(s[start++] != s[end--])
                return false;
            
        }
        
        return true;
        
    }
    void solve(string s,int index, vector<string> path,vector<vector<string>>& ans){
        
        //base case
        if(index == s.size()){
            
            ans.push_back(path);
            return;
            
        }
        
        //iterate through the string s from index till end
        
        for(int i = index;i<s.size();i++){
            
            //check for palindrome
            if(isPalindrome(s,index,i)){
                
                path.push_back(s.substr(index, i - index + 1));
                solve(s,i+1,path,ans);
                path.pop_back();
                
            }
            
        }
        
        
        
    }
    
    vector<vector<string>> partition(string s) {
        
        int index = 0;
        vector<vector<string>> ans;
        vector<string> path;
        
        solve(s,index,path,ans);
        
        return ans;
        
    }
};