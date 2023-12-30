class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        map<int,int> freq;
        
        for(int i = 0;i<words.size();i++){
            
            for(char c : words[i])
                freq[c]++;
            
        }
                
        for(auto i : freq){
            
            if(i.second % words.size() != 0)
                return false;
            
        }
        
        return true;
        
    }
};