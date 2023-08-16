class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        //maintain hashArray for the letter freq of s and also for t
        
        vector<int> first(26,0);
        vector<int> second(26,0);
            
        for(int i = 0;i<s.size();i++){
            
            first[ s[i] - 'a' ]++;
            
            second[ t[i] - 'a' ]++;
            
        }
        
        //check whether the frequencies are same
        for(int i = 0;i<26;i++){
            
            if(first[i] != second[i])
                return false;
            
        }
        
        return true;
        
    }
};