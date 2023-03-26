class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        

        int ans1 = edges[0][0];
        int ans2 = edges[0][1];
            
            int u = edges[1][0];
            int v = edges[1][1];
            
            if(ans1 == u || ans1 == v)return ans1;
            else return ans2;
        
        
    }
};