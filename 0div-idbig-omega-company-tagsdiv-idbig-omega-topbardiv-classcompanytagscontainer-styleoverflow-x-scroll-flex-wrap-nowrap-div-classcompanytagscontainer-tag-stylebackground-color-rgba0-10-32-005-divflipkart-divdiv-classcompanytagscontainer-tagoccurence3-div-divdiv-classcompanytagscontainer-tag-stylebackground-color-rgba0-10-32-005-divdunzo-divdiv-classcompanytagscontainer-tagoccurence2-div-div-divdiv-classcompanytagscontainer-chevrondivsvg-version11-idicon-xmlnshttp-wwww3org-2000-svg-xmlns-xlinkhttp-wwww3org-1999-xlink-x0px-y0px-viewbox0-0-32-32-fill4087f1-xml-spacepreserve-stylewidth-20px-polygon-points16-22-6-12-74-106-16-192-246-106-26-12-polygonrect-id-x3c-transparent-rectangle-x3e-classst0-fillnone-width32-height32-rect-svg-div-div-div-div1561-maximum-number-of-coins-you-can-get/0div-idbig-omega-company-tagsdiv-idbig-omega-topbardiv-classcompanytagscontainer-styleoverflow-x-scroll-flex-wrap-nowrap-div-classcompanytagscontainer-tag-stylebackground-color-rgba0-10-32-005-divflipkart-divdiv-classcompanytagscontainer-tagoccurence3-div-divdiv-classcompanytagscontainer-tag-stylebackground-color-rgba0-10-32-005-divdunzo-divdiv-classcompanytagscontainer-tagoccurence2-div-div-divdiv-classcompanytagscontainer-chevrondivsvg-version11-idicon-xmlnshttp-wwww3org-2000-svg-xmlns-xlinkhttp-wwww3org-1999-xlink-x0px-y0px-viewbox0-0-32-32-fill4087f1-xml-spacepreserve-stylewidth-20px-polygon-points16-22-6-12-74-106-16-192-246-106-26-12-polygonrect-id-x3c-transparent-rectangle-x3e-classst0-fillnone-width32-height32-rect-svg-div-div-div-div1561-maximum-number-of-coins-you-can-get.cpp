class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        //sort the piles so we to get larger on right and smaller on left
        sort(piles.begin(),piles.end());
        
        int maxi = 0;
        
        for(int i = piles.size()/3;i<piles.size();i += 2){
            
            maxi += piles[i];
            
        }
        
        return maxi;
        
    }
};