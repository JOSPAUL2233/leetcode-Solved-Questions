class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int left = 0;
        map<char,int> freq;//stores the frequency of a,b and c
        
        int count = 0;
        
        for(int right = 0;right<s.size();right++){
            
            //increase the frequency
            freq[s[right]]++;
            
            //shrink window from left as many times we have got a valid subString
            while((left <= right) && (freq['a']>0) && (freq['b']>0) && (freq['c']>0)){
                
                //update answer, if this is a valid substring then it will
                //form substring will all the elements right of right pointer till the end
                count += (s.size() - right);
                
                freq[s[left]]--;
                left++;
                
            }
            
        }
        
        return count;
        
    }
};