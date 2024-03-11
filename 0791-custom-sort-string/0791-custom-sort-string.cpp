class Solution {
public:
    string customSortString(string order, string s){
        
        unordered_map<char,int> freq;
        string ans;
        
        for(char c : s) freq[c]++;
        
        for(int c : order)
            while(freq[c]-- > 0)
                ans.push_back(c);
                    
        
        for(auto p : freq){
            
            while(p.second-- > 0)
                ans.push_back(p.first);
        }
        
        return ans;
        
    }
};