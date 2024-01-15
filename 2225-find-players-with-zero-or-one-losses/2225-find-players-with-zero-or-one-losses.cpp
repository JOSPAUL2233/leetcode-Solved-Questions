class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<int> notLost;
        vector<int> oneLost;
        
        map<int,int> won;
        map<int,int> lost;
        
        set<int> st;
        
        for(int i = 0;i<matches.size();i++){
            
            won[matches[i][0]]++;
            lost[matches[i][1]]++;
            
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
            
        }
        
        //fill not lost and onelost
        
        for(auto i : st){
            
            if(lost[i] == 0)
                notLost.push_back(i);
            
            if(lost[i] == 1)
                oneLost.push_back(i);
            
        }
        
        return {notLost,oneLost};
        
    }
};