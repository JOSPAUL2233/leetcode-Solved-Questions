class Solution {
public:
    int findComplement(int num) {
        
        int ans = num;
        
        for(long i = 1;i<=num;i*=2){
            ans^=i;
        }
        
        return ans;
        
    }
};