class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        
        int count = 0;
        
        for(int i = 0;i<32;i++){
            
            // (a >> i)shifts the a by i places and (& 1) gives the last bit
            if((start >> i & 1)^ (goal >> i & 1) == 1 )
                count++;
            
        }
        
        return count;
        
    }
};