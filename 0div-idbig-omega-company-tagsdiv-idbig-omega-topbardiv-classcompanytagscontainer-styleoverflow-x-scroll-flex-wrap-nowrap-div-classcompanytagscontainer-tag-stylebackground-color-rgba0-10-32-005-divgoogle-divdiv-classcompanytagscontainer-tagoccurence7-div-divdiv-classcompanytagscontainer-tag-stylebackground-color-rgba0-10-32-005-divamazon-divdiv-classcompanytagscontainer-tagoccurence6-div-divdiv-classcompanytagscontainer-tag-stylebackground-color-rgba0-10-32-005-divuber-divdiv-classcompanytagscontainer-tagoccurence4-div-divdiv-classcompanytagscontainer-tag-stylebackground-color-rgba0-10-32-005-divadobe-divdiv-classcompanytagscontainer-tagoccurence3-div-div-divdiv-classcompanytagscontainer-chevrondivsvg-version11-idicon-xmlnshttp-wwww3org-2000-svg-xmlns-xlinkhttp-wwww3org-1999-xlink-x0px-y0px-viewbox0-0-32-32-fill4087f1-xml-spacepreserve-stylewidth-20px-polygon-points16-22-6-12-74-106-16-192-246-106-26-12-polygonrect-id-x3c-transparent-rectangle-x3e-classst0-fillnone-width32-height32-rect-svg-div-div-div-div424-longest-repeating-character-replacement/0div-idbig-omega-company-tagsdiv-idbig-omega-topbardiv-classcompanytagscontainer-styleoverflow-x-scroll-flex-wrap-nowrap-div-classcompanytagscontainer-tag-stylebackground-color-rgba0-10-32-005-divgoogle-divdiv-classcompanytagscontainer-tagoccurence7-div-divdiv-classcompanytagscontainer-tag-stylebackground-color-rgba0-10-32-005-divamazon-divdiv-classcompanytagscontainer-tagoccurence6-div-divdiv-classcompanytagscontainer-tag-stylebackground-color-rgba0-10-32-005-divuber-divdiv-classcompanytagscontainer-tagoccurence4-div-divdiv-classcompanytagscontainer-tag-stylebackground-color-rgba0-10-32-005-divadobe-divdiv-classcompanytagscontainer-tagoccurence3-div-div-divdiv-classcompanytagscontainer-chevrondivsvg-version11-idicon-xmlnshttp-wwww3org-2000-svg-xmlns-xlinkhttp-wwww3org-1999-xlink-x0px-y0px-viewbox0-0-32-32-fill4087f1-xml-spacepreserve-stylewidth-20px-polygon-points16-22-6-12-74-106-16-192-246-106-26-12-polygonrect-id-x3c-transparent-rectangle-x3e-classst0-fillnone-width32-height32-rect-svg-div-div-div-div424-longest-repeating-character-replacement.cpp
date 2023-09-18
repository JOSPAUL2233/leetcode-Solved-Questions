class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxLength = INT_MIN;
        int left = 0;
        
        int maxFreq = INT_MIN;
        
        map<char,int> freq;
        
        for(int right = 0;right<s.size();right++){
            
            //increment the frequency
            freq[s[right]]++;
            
            //store the maximum frequency
            maxFreq = max(maxFreq, freq[s[right]] );
            
            int windowSize = right - left + 1;
            
            if( (windowSize - maxFreq) > k){
                
                freq[s[left]]--;
                left++;
                
            }
            
            int length = right - left + 1;
            maxLength = max(maxLength,length);
            
        }
        
        return maxLength;
        
    }
};