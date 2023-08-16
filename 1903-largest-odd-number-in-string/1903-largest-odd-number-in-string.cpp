class Solution {
public:
    string largestOddNumber(string num) {
        
        //search for right most odd integer
        
        string res = "";
        
        for(int i = num.size()-1 ; i >= 0 ; i--){
            
            int digit = num[i] - '0';
            
            if(digit % 2 == 1){
                
                res = num.substr(0,i+1);
                break;
                
            }
            
        }
        
        return res;
        
    }
};