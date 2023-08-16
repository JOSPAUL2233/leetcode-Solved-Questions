class Solution {
public:
    int romanToInt(string s) {
        
        //store the roman symbols and values in a hashmap
        map<char,int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.size();i++){
            
            int current = s[i];
            
            //at the last symbol
            if(i+1 == s.size()){
                
                ans += roman[current];
                break;
                
            }
                
            int next = s[i+1];
            
            if(roman[current] < roman[next]){
                
                ans += (roman[next] - roman[current]);
                i++;
                
            }else{
                
                ans += roman[current];
            }
                        
        }
        
        return ans;
        
    }
};