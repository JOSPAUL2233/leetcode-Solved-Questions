class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<string,int> mp;
        int count = 0;
        
        for(string s : words1){
            
            if(mp[s] == 0)mp[s] = 1;
            else if(mp[s] == 1)mp[s] = -1;//if there are more than one elements
            
        }
        
        for(string s: words2){
            
            if(mp[s]==1)mp[s]=2;
            else if(mp[s]==2)mp[s] = -1;
            
        }
        
        for(auto i : mp){
            
            if(i.second==2)count++;
            
        }
        
        return count;
        
    }
};