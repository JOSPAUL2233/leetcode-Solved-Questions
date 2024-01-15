class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<int> notLost;
        vector<int> oneLost;
        
        map<int,int> lost;
                
        for(int i = 0;i<matches.size();i++){
            
            int winner = matches[i][0];
            int loser = matches[i][1];
            
            if(lost.find(winner) == lost.end())
                lost[winner] = 0;
    
            lost[loser]++;
                        
        }
        
        //fill not lost and onelost
        
        for(auto i : lost){
            
            if(i.second == 0)
                notLost.push_back(i.first);
            
            if(i.second == 1)
                oneLost.push_back(i.first);
            
        }
        
        return {notLost,oneLost};
        
    }
};