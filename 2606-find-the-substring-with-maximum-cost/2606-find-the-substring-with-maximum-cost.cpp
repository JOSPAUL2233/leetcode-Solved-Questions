class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        unordered_map<char,int> alphaValue;
        char temp = 'a';
        int n = s.size();
        
        int max = 0;
        
        //alphabet Stored in respective values
        while(temp <= 'z'){
            
            alphaValue[temp] = temp - 'a' + 1;
            temp = temp + 1;
        }
        
        //overwrite the values with the given values
        
        for(int i = 0;i<chars.size();i++){
            
            alphaValue[chars[i]] = vals[i];
            
        }
        
        
        int sum = 0;
        
        //traverse through the string
        
        for(int i = 0;i<s.size();i++){
            
            sum += alphaValue[s[i]];
            
            //if it is leading to -ve number re-initialize it by 0
            if(sum < 0)sum = 0;
            
            max = sum > max ? sum : max;

        }
        
        return max;
        
    }
};