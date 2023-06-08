class Solution {
    
    void solve(vector<string> mapping,string digits,string path,
                vector<string> &ans, int index){
        
        if(index == digits.size()){
            
            ans.push_back(path);
            return ;
            
        }
        
        string letters = mapping[digits[index] - '0'];
                
        for(int i = 0;i<letters.size();i++){
            
            path.push_back(letters[i]);
            solve(mapping,digits,path,ans,index+1);
            path.pop_back();
            
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        //edge case
        if(digits.size()==0)return{};
        
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string path;
        
        int index = 0;
        
        solve(mapping,digits,path,ans,index);
        
        return ans;
        
    }
};