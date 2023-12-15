class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        map<string,bool> visited;
        
        for(int i = 0;i<paths.size();i++){
            
            visited[paths[i][0]] = true;
            
        }
        
        for(int i = 0;i<paths.size();i++){
            
            if(!visited[paths[i][1]])
                return paths[i][1];
            
        }
        
        return "";
        
    }
};