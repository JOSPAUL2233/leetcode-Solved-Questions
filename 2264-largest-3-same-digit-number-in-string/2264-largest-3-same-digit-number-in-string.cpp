class Solution {
public:
    string largestGoodInteger(string num) {
        
        string ans = "";
        int maxi = -1;
        
        for(int i = 2;i<num.size();i++){
            
            if(num[i] == num[i-1] && num[i] == num[i-2]){
                
                if(num[i]-'0' > maxi){
                    
                    ans = num.substr(i-2,3);
                    maxi = num[i]-'0';
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};