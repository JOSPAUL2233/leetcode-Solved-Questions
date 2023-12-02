class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int count = 0;
        
        vector<int> freq(26,0);
        
        for(char c : chars)
            freq[c-'a']++;
        
        for(string s : words){
            
            vector<int> temp = freq;
            bool flag = true;
            
            for(char c : s){
                
                if(temp[c-'a'] <= 0){
                    flag = false;
                    break;
                }
                
                temp[c-'a']--;
                
            }
            
            if(flag)
                    count += s.size();
            
        }
        
        return count;
        
    }
};