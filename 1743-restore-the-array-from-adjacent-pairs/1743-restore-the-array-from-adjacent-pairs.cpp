class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        vector<int> ans;
        map<int,vector<int>> gh;
        
        //push all in the graph map
        for(auto i : adjacentPairs){
            
            gh[i[0]].push_back(i[1]);
            gh[i[1]].push_back(i[0]);
                        
        }
        
        //get the starting element pair
        for(auto i : gh){
            
            if(i.second.size() == 1){
                
                //push both the elements and break
                ans.push_back(i.first);
                ans.push_back(i.second[0]);
                break;
                
            }
            
        }
        
        //get the rest of the elments
        while(ans.size() < gh.size()){
            
            //get last and secondlast node from the answer
            int last = ans[ans.size()-1];
            int secondLast = ans[ans.size()-2];
            
            vector<int> node = gh[last];
            
            if(node[0] != secondLast)
                ans.push_back(node[0]);
            else
                ans.push_back(node[1]);
            
        }
        
        return ans;
        
    }
};