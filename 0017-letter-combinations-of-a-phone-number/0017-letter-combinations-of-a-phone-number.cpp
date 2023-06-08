class Solution {
    
    void solve(vector<string> mapping,string digits,string path,
                vector<string> &ans, int index){
        
        //when answer is ready
        if(index == digits.size()){     
            ans.push_back(path);
            return ;
        }
        
        //extract the corresponding string letters
        string letters = mapping[digits[index] - '0'];
        
        //iterate through all the string letters
        for(int i = 0;i<letters.size();i++){
            
            path.push_back(letters[i]);//add the element and do recursion
            solve(mapping,digits,path,ans,index+1);
            path.pop_back();//remove the currently added element while going back
            
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        //edge case
        if(digits.size()==0)return{};
        
        //make a mapping for numbers and it's letters
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string path;
        
        int index = 0;
        solve(mapping,digits,path,ans,index);
        
        return ans;
        
    }
};