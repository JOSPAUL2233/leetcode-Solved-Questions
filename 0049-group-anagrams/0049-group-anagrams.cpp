class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string> sor = strs;
        vector<int> visited(strs.size(),0);
        
        for(int i = 0;i<sor.size();i++){
            
            sort(sor[i].begin(),sor[i].end());
            
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0;i<sor.size();i++){
            
            if(visited[i])
                continue;
            
            vector<string> vec;
            vec.push_back(strs[i]);
            
            for(int j = i+1;j<sor.size();j++){
                
                if(sor[i] == sor[j]){
                    vec.push_back(strs[j]);
                    visited[j] = 1;
                }
                
            }
            
            ans.push_back(vec);
            
        }
        
        return ans;
        
    }
};