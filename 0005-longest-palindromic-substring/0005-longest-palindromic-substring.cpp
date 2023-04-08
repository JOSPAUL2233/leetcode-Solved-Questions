class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size()<=1)return s;
        
        int max_length = 1;
        int index = 0;
        
        int left = 0;
        int right = 0;
        
        string ans;
        
        
        //if palandrome is odd
        
        for(int i = 0;i<s.size();i++){
            
            left = right = i;
            
            while(left >= 0 && right <= s.size() && (s[left] == s[right])){
                
                left--;
                right++;
                
            }
            
            left++;
            right--;
            
            int len = right-left+1;
            
            if(max_length < len){
                
                max_length = len;
                index = left;
                
            }
            
        }
        
        //if palandrome is even
        
        for(int i = 0;i<s.size();i++){
            
            left = i;
            right = i+1;
            
            while(left >= 0 && right <= s.size() && (s[left] == s[right])){
                
                left--;
                right++;
                
            }
            
            left++;
            right--;
            
            int len = right-left+1;
            
            if(max_length < len){
                
                max_length = len;
                index = left;
                
            }
            
        }
        
        ans = s.substr(index,max_length);
        
        return ans;
        
    }
};