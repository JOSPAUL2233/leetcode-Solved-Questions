class Solution {
public:
    int characterReplacement(string s, int k) {
        
              unordered_map<char,int> m;
        int maxLen=0,l=0,r=0,Max=0;
        while(r<s.size()){
            m[s[r]]++;
            Max=max(Max,m[s[r]]);
            
            if(r-l+1-Max>k){
                m[s[l]]--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
        
    }
};