class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(),piles.end());
        
        int ptr1 = 0;
        int ptr2 = piles.size()-1;
        
        int maxi = 0;
        
        while(ptr1<ptr2){
            
            maxi += piles[ptr2-1];
            
            ptr1++;
            ptr2 -= 2;
            
        }
        
        return maxi;
        
    }
};