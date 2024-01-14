class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size())
            return false;
        
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        
        for(int i = 0;i<word1.size();i++){
            
            char c = word1[i];
            freq1[c-'a']++;
            
        }

        for(int i = 0;i<word2.size();i++){
            
            char c = word2[i];
            
            if(freq1[c-'a'] == 0)
                return false;  
            
            freq2[c-'a']++;
            
        }
        
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        return freq1==freq2;
        
    }
};