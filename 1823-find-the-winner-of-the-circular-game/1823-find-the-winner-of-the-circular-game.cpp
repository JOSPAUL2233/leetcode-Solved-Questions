class Solution {
    
    void solve(vector<int> &players,int start,int k){
        
        if(players.size()==1)return;
        
        start = start + k;//-------------chooseing next position
        
        start = start % players.size();//------making sure that it does not overflow the size
        
        players.erase(players.begin()+start); //-----excecute the player
        
        solve(players,start,k); //go for next iteration from next player
        
    }
    
public:
    int findTheWinner(int n, int k) {
        
        vector<int> players;
        
        int start = 0;
        
        for(int i = 0;i<n;i++){
            
            players.push_back(i+1);
            
        }
        
        
        k--;
        solve(players,start,k);
        
        
        return players[0];
        
    }
};