class Solution {
public:
    
    
    void solve(string digits,vector<string>& ans,string mapping[],int index, string output){
        
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
    
        int number = digits[index] - '0';
        
        string str = mapping[number];
        
        
        for(int i = 0;i<str.size();i++){
            
            output.push_back(str[i]);
            solve(digits,ans,mapping,index+1,output);
            output.pop_back();
            
        }
        
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        
        
        vector<string> ans;
        
        if(digits.size()==0)return ans;
        
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        int index = 0;
        
        string output = "";
        
        solve(digits,ans,mapping,index,output);
        
        return ans;
        
        
        
    }
};