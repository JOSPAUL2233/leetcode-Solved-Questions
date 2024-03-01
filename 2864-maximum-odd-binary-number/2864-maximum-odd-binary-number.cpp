class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int count = 0;
        
        for(char c : s) if(c == '1')count++;
        
        int size = s.size()-count;
        count--;
        
        string ans;
        while(count--){
            ans.push_back('1');
        }
        
        while(size--) ans.push_back('0');
        
        ans.push_back('1');
        
        return ans;
    }
};