class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        //first maintain a map that stores char --> fistOccurance , lastOccurance
        
        map<char,pair<int,int>> mp;
        
        //find the first occurance
        for(int i = 0;i<s.size();i++){
            
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = {i,-1};
            
        }
        
        //find the last occurance
        for(int i = s.size()-1;i>=0;i--){
            
            if(mp[s[i]].second == -1){
                mp[s[i]].second = i;
            }
            
        }
        
        int ans = 0;
        
        for(auto m : mp){
            
            int start = m.second.first;
            int end = m.second.second;
            
            //make a set to get the unique characters
            set<char> st;
            
            for(int i = start+1;i<end;i++){
                
                st.insert(s[i]);
                
            }
            
            ans += st.size();
            
        }
        
        return ans;
        
    }
};